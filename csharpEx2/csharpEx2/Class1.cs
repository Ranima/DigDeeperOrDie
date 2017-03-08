using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace csharpEx2
{
    class Vec2
    {
        public float x;
        public float y;

        public Vec2(float v1)
        {
            x = v1;
            y = 0;
        }
        public Vec2(float v1, float v2)
        {
            x = v1;
            y = v2;
        }

        public static Vec2 operator + (Vec2 a, Vec2 b)
        {
            return new Vec2(a.x + b.x, a.y + b.y);
        }
        public static Vec2 operator -(Vec2 a, Vec2 b)
        {
            return new Vec2(a.x - b.x, a.y - b.y);
        }
        public static Vec2 operator *(Vec2 a, float b)
        {
            return new Vec2(a.x * b, a.y * b);
        }
        public static Vec2 operator *(float a, Vec2 b)
        {
            return new Vec2(b.x * a, b.y * a);
        }
        public static Vec2 operator /(Vec2 a, float b)
        {
            return new Vec2(a.x / b, a.y / b);
        }

        public override bool Equals(object obj)
        {
            return obj is Vec2 && this == (Vec2)obj;
        }

        public override int GetHashCode()
        {
            return x.GetHashCode() ^ y.GetHashCode();
        }

        public float Magnitude()
        {
            float a = (x - 0);
            float b = (y - 0);
            float c = (float)Math.Sqrt((a * a) + (b * b));
            return c;
        }
        

        public Vec2 Normal()
        {
            Vec2 returnValue = this;
            float mag = Magnitude();

            returnValue.x /= mag;
            returnValue.y /= mag;

            return returnValue;
        }

        public void Normalize()
        {
            x = x / Magnitude();
            y = y / Magnitude();
        }

        public static float Distance(Vec2 start, Vec2 end)
        {
            float a = Math.Abs(start.x - end.x);
            float b = Math.Abs(start.y - end.y);
            float c = (float)Math.Sqrt((a * a) + (b * b));
            return c;
        }

        // 5,0
        public override string ToString()
        {
            // 5
            // "5"
            string str = x.ToString() + "," + y.ToString();
            string fmt = string.Format("{0},{1}", x, y);

            return x.ToString() + "," + y.ToString();
            //return new string("hi");
        } 
    }
}
