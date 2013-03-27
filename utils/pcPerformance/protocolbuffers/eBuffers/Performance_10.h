#ifndef _Performance_10_H_
#define _Performance_10_H_

#include <stdint.h>
#include <array>
#include <string>
#include <vector>

namespace performance
{
    class Performance
    {
    public:
        Performance();
        ~Performance();
        Performance(const Performance &x);
        Performance(Performance &&x);
        Performance& operator=(const Performance &x);
        Performance& operator=(Performance &&x);
        
        inline void m1(int32_t _m1)
        {
            m_m1 = _m1;
        }

        inline int32_t m1() const
        {
            return m_m1;
        }

        inline int32_t& m1()
        {
            return m_m1;
        }
        inline void m2(int32_t _m2)
        {
            m_m2 = _m2;
        }

        inline int32_t m2() const
        {
            return m_m2;
        }

        inline int32_t& m2()
        {
            return m_m2;
        }
        inline void m3(int32_t _m3)
        {
            m_m3 = _m3;
        }

        inline int32_t m3() const
        {
            return m_m3;
        }

        inline int32_t& m3()
        {
            return m_m3;
        }
        inline void m4(int32_t _m4)
        {
            m_m4 = _m4;
        }

        inline int32_t m4() const
        {
            return m_m4;
        }

        inline int32_t& m4()
        {
            return m_m4;
        }
        inline void m5(int32_t _m5)
        {
            m_m5 = _m5;
        }

        inline int32_t m5() const
        {
            return m_m5;
        }

        inline int32_t& m5()
        {
            return m_m5;
        }
        inline void m6(int32_t _m6)
        {
            m_m6 = _m6;
        }

        inline int32_t m6() const
        {
            return m_m6;
        }

        inline int32_t& m6()
        {
            return m_m6;
        }
        inline void m7(int32_t _m7)
        {
            m_m7 = _m7;
        }

        inline int32_t m7() const
        {
            return m_m7;
        }

        inline int32_t& m7()
        {
            return m_m7;
        }
        inline void m8(int32_t _m8)
        {
            m_m8 = _m8;
        }

        inline int32_t m8() const
        {
            return m_m8;
        }

        inline int32_t& m8()
        {
            return m_m8;
        }
        inline void m9(int32_t _m9)
        {
            m_m9 = _m9;
        }

        inline int32_t m9() const
        {
            return m_m9;
        }

        inline int32_t& m9()
        {
            return m_m9;
        }
        inline void m10(int32_t _m10)
        {
            m_m10 = _m10;
        }

        inline int32_t m10() const
        {
            return m_m10;
        }

        inline int32_t& m10()
        {
            return m_m10;
        }
        
    private:
        int32_t m_m1;
        int32_t m_m2;
        int32_t m_m3;
        int32_t m_m4;
        int32_t m_m5;
        int32_t m_m6;
        int32_t m_m7;
        int32_t m_m8;
        int32_t m_m9;
        int32_t m_m10;
    };
}

#endif // _Performance_10_H_