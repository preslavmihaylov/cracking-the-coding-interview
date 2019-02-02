#ifndef PSTRUCTS_BIT_OPS_H
#define PSTRUCTS_BIT_OPS_H

#include <iostream>
#include <algorithm>
#include <cstdint>

namespace pstructs
{
    class bit_ops
    {
    public:
        bit_ops() = delete;
        
        static uint32_t bitsCnt(uint32_t num)
        {
            int cnt = 0;
            while (num != 0)
            {
                num >>= 1;
                cnt++;
            }
            
            return cnt;
        }

        static int clearBit(uint32_t num, uint8_t pos)
        {
            return num & ~(1 << pos);
        }

        static int raiseBit(uint32_t num, uint8_t pos)
        {
            return num | (1 << pos);
        }

        static int setBit(uint32_t num, uint8_t pos, bool bit)
        {
            return bit ? raiseBit(num, pos) : clearBit(num, pos);
        }

        static int getBit(uint32_t num, uint8_t pos)
        {
            return (num >> pos) & 1;
        }

        static std::string toBinaryString(uint32_t num)
        {
            std::ostringstream oss;
            while (num != 0)
            {
                oss << bit_ops::getBit(num, 0);
                num >>= 1;
            }

            std::string res = oss.str();
            std::reverse(res.begin(), res.end());

            return res;
        }
    };
}

#endif
