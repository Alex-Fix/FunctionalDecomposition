using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace UI
{
    public static class Extentions
    {
        public static byte[] ToBytes(this string input)
        {
            return Encoding.UTF8.GetBytes(input);
        }
    }
}
