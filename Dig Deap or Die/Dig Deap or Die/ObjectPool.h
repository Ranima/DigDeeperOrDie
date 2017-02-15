#pragma once

template<class T>
class ObjectPool
{
	struct __intern
	{
		bool open;
		size_t next;
		T* data;
	};

	__intern *m_data;
	size_t	  m_size;

	size_t openHead, fillHead;

public:

	ObjectPool(const ObjectPool &) = delete;
	ObjectPool &operator=(const ObjectPool &) = delete;
	ObjectPool(ObjectPool &&) = delete;
	ObjectPool &operator=(ObjectPool &&) = delete;

	~ObjectPool() { delete[] m_data; }

	ObjectPool(size_t a_size) : m_size(a_size), openHead(0), fillHead(m_size)
	{
		m_data = new __intern[m_size];

		for (size_t i = 0; i < m_size; ++i)
		{
			m_data[i].open = true;
			m_data[i].next = i + 1;
		}
	}

	class iterator
	{
		ObjectPool *m_ref;
		size_t		m_idx;

		friend class ObjectPool<T>;

		iterator(ObjectPool *a_ref, size_t a_idx) : m_ref(a_ref), m_idx(a_idx) {}
	public:
		iterator() : m_ref(nullptr), m_idx(0) {}

		T &operator* () { return  m_ref->m_data[m_idx].data; }
		T *operator->() { return &m_ref->m_data[m_idx].data; }
		T *operator& () { return &m_ref->m_data[m_idx].data; }

		const T &operator* () { return  m_ref->m_data[m_idx].data; }
		const T *operator->() { return &m_ref->m_data[m_idx].data; }
		const T *operator& () { return &m_ref->m_data[m_idx].data; }

		iterator &operator++() { m_idx = m_ref->m_data[m_idx].data; return *this; }
		iterator operator++(int) { auto that = *this; operator++(); return that; }

		bool operator==(const iterator &O) const { return m_ref == O.m_ref && m_idx == O.m_idx; }
		bool operator!=(const iterator &O) const { return !operator==(O); }

		operator bool() const { return m_ref != nullptr && m_idx < m_ref->m_size && !m_ref[m_idx].openHead; }

		operator T*() { return operator&(); }
		operator const	T*() const { return operator&(); }

		iterator &free() { return *this = m_ref->pop(*this); }
	};

	iterator push(const T &val = T())
	{
		if (openHead >= m_size) return iterator();

		size_t idx = openHead;

		m_data[idx].data = val;
		m_data[idx].open = false;

		openHead = m_data[openHead].next;

		if (idx < fillHead)
		{
			m_data[idx].next = fillHead;
			fillHead = idx;
		}
		else
		{
			size_t left = idx;

			while (m_data[--left].open);

			m_data[idx].next = m_data[left].next;
			m_data[left].next = idx;
		}
		return iterator(this, idx);
	}

	iterator pop(iterator it)
	{
		if (!(it && it.m_ref == this)) return iterator();

		size_t idx = it.m_idx;
		++it;

		m_data[idx].open = true;

		if (idx == fillHead)
			fillHead = m_data[idx].next;

		else
		{
			size_t left = idx;
			while (m_data[--left].open);
			m_data[left].next = m_data[idx].next;
		}

		if (idx < openHead)
		{
			m_data[idx].next = openHead;
			openHead = idx;
		}
		else
		{
			size_t left = idx;
			while (!m_data[--left].open);

			m_data[idx].next = m_data[left].next;
			m_data[left].next = idx;
		}
		return it;
	}

	iterator begin() { return iterator(this, fillHead); }
	iterator end() { return iterator(this, m_size); }
};