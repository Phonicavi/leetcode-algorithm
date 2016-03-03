class Solution {
public:
    uint32_t reverseBits2(uint32_t n) {
        // since the number is 32 bits
        // n = 0vABCDEFGH
        n = (n >> 16) | (n << 16); // now, n = 0vEFGHABCD
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8); // now, n = 0vGHEFCDAB
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4); // now, n = 0vHGFEDCBA
        n = ((n & 0b11001100110011001100110011001100) >> 2) | ((n & 0b00110011001100110011001100110011) << 2); // for each hex-bit: 1100, 0011
        n = ((n & 0b10101010101010101010101010101010) >> 1) | ((n & 0b01010101010101010101010101010101) << 1); // for each hex-bit: 1010, 0101
        return n;
    }
    
    uint32_t reverseBits(uint32_t n) {
        // since the number is 32 bits
        // n = 0vABCDEFGH
        n = (n >> 16) | (n << 16); // now, n = 0vEFGHABCD
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8); // now, n = 0vGHEFCDAB
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4); // now, n = 0vHGFEDCBA
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2); // for each hex-bit: 1100, 0011
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1); // for each hex-bit: 1010, 0101
        return n;
    }
};