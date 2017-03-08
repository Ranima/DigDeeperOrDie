using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace csharpEx2
{
    public struct trackData
    {
        public string trackName = string.Format("unknown");

        public string artistName;

        public string albumName;
        
        public float trackDuration;

        public int trackNumber;

        public trackData(string track) { }
        public trackData(string track, float trackDuration) { }
        public trackData(string track, float trackDuration, string albumName) { }
        public trackData(string track, float trackDuration, string albumName, string artist) { }
        public trackData(string track, float trackDuration, string albumName, string artist, int numb) { }

        public static bool operator == (trackData lhs, trackData rhs) { }
        public static bool operator != (trackData lhs, trackData rhs) { }

        public override bool Equals(object obj) {return base.Equals(obj);}
        public override int GetHashCode() {return base.GetHashCode();}
        public override string ToString() {return base.ToString();}
    }

    class TrackData
    {

    }
}
