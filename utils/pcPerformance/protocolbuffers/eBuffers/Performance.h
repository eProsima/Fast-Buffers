#ifndef _Performance_H_
#define _Performance_H_

#include <stdint.h>
#include <array>
#include <string>
#include <vector>

namespace performance
{
    class mfloats
    {
    public:
        mfloats();
        ~mfloats();
        mfloats(const mfloats &x);
        mfloats(mfloats &&x);
        mfloats& operator=(const mfloats &x);
        mfloats& operator=(mfloats &&x);
        
        inline void m1(float _m1)
        {
            m_m1 = _m1;
        }

        inline float m1() const
        {
            return m_m1;
        }

        inline float& m1()
        {
            return m_m1;
        }
        inline void m2(float _m2)
        {
            m_m2 = _m2;
        }

        inline float m2() const
        {
            return m_m2;
        }

        inline float& m2()
        {
            return m_m2;
        }
        inline void m3(float _m3)
        {
            m_m3 = _m3;
        }

        inline float m3() const
        {
            return m_m3;
        }

        inline float& m3()
        {
            return m_m3;
        }
        inline void m4(float _m4)
        {
            m_m4 = _m4;
        }

        inline float m4() const
        {
            return m_m4;
        }

        inline float& m4()
        {
            return m_m4;
        }
        inline void m5(float _m5)
        {
            m_m5 = _m5;
        }

        inline float m5() const
        {
            return m_m5;
        }

        inline float& m5()
        {
            return m_m5;
        }
        inline void m6(float _m6)
        {
            m_m6 = _m6;
        }

        inline float m6() const
        {
            return m_m6;
        }

        inline float& m6()
        {
            return m_m6;
        }
        inline void m7(float _m7)
        {
            m_m7 = _m7;
        }

        inline float m7() const
        {
            return m_m7;
        }

        inline float& m7()
        {
            return m_m7;
        }
        inline void m8(float _m8)
        {
            m_m8 = _m8;
        }

        inline float m8() const
        {
            return m_m8;
        }

        inline float& m8()
        {
            return m_m8;
        }
        inline void m9(float _m9)
        {
            m_m9 = _m9;
        }

        inline float m9() const
        {
            return m_m9;
        }

        inline float& m9()
        {
            return m_m9;
        }
        
    private:
        float m_m1;
        float m_m2;
        float m_m3;
        float m_m4;
        float m_m5;
        float m_m6;
        float m_m7;
        float m_m8;
        float m_m9;
    };
    class mdoubles
    {
    public:
        mdoubles();
        ~mdoubles();
        mdoubles(const mdoubles &x);
        mdoubles(mdoubles &&x);
        mdoubles& operator=(const mdoubles &x);
        mdoubles& operator=(mdoubles &&x);
        
        inline void m1(double _m1)
        {
            m_m1 = _m1;
        }

        inline double m1() const
        {
            return m_m1;
        }

        inline double& m1()
        {
            return m_m1;
        }
        inline void m2(double _m2)
        {
            m_m2 = _m2;
        }

        inline double m2() const
        {
            return m_m2;
        }

        inline double& m2()
        {
            return m_m2;
        }
        inline void m3(double _m3)
        {
            m_m3 = _m3;
        }

        inline double m3() const
        {
            return m_m3;
        }

        inline double& m3()
        {
            return m_m3;
        }
        inline void m4(double _m4)
        {
            m_m4 = _m4;
        }

        inline double m4() const
        {
            return m_m4;
        }

        inline double& m4()
        {
            return m_m4;
        }
        inline void m5(double _m5)
        {
            m_m5 = _m5;
        }

        inline double m5() const
        {
            return m_m5;
        }

        inline double& m5()
        {
            return m_m5;
        }
        inline void m6(double _m6)
        {
            m_m6 = _m6;
        }

        inline double m6() const
        {
            return m_m6;
        }

        inline double& m6()
        {
            return m_m6;
        }
        inline void m7(double _m7)
        {
            m_m7 = _m7;
        }

        inline double m7() const
        {
            return m_m7;
        }

        inline double& m7()
        {
            return m_m7;
        }
        inline void m8(double _m8)
        {
            m_m8 = _m8;
        }

        inline double m8() const
        {
            return m_m8;
        }

        inline double& m8()
        {
            return m_m8;
        }
        inline void m9(double _m9)
        {
            m_m9 = _m9;
        }

        inline double m9() const
        {
            return m_m9;
        }

        inline double& m9()
        {
            return m_m9;
        }
        
    private:
        double m_m1;
        double m_m2;
        double m_m3;
        double m_m4;
        double m_m5;
        double m_m6;
        double m_m7;
        double m_m8;
        double m_m9;
    };
    class msfixed32s
    {
    public:
        msfixed32s();
        ~msfixed32s();
        msfixed32s(const msfixed32s &x);
        msfixed32s(msfixed32s &&x);
        msfixed32s& operator=(const msfixed32s &x);
        msfixed32s& operator=(msfixed32s &&x);
        
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
    };
    class msfixed64s
    {
    public:
        msfixed64s();
        ~msfixed64s();
        msfixed64s(const msfixed64s &x);
        msfixed64s(msfixed64s &&x);
        msfixed64s& operator=(const msfixed64s &x);
        msfixed64s& operator=(msfixed64s &&x);
        
        inline void m1(int64_t _m1)
        {
            m_m1 = _m1;
        }

        inline int64_t m1() const
        {
            return m_m1;
        }

        inline int64_t& m1()
        {
            return m_m1;
        }
        inline void m2(int64_t _m2)
        {
            m_m2 = _m2;
        }

        inline int64_t m2() const
        {
            return m_m2;
        }

        inline int64_t& m2()
        {
            return m_m2;
        }
        inline void m3(int64_t _m3)
        {
            m_m3 = _m3;
        }

        inline int64_t m3() const
        {
            return m_m3;
        }

        inline int64_t& m3()
        {
            return m_m3;
        }
        inline void m4(int64_t _m4)
        {
            m_m4 = _m4;
        }

        inline int64_t m4() const
        {
            return m_m4;
        }

        inline int64_t& m4()
        {
            return m_m4;
        }
        inline void m5(int64_t _m5)
        {
            m_m5 = _m5;
        }

        inline int64_t m5() const
        {
            return m_m5;
        }

        inline int64_t& m5()
        {
            return m_m5;
        }
        inline void m6(int64_t _m6)
        {
            m_m6 = _m6;
        }

        inline int64_t m6() const
        {
            return m_m6;
        }

        inline int64_t& m6()
        {
            return m_m6;
        }
        inline void m7(int64_t _m7)
        {
            m_m7 = _m7;
        }

        inline int64_t m7() const
        {
            return m_m7;
        }

        inline int64_t& m7()
        {
            return m_m7;
        }
        inline void m8(int64_t _m8)
        {
            m_m8 = _m8;
        }

        inline int64_t m8() const
        {
            return m_m8;
        }

        inline int64_t& m8()
        {
            return m_m8;
        }
        inline void m9(int64_t _m9)
        {
            m_m9 = _m9;
        }

        inline int64_t m9() const
        {
            return m_m9;
        }

        inline int64_t& m9()
        {
            return m_m9;
        }
        
    private:
        int64_t m_m1;
        int64_t m_m2;
        int64_t m_m3;
        int64_t m_m4;
        int64_t m_m5;
        int64_t m_m6;
        int64_t m_m7;
        int64_t m_m8;
        int64_t m_m9;
    };
    class mfixed32s
    {
    public:
        mfixed32s();
        ~mfixed32s();
        mfixed32s(const mfixed32s &x);
        mfixed32s(mfixed32s &&x);
        mfixed32s& operator=(const mfixed32s &x);
        mfixed32s& operator=(mfixed32s &&x);
        
        inline void m1(uint32_t _m1)
        {
            m_m1 = _m1;
        }

        inline uint32_t m1() const
        {
            return m_m1;
        }

        inline uint32_t& m1()
        {
            return m_m1;
        }
        inline void m2(uint32_t _m2)
        {
            m_m2 = _m2;
        }

        inline uint32_t m2() const
        {
            return m_m2;
        }

        inline uint32_t& m2()
        {
            return m_m2;
        }
        inline void m3(uint32_t _m3)
        {
            m_m3 = _m3;
        }

        inline uint32_t m3() const
        {
            return m_m3;
        }

        inline uint32_t& m3()
        {
            return m_m3;
        }
        inline void m4(uint32_t _m4)
        {
            m_m4 = _m4;
        }

        inline uint32_t m4() const
        {
            return m_m4;
        }

        inline uint32_t& m4()
        {
            return m_m4;
        }
        inline void m5(uint32_t _m5)
        {
            m_m5 = _m5;
        }

        inline uint32_t m5() const
        {
            return m_m5;
        }

        inline uint32_t& m5()
        {
            return m_m5;
        }
        inline void m6(uint32_t _m6)
        {
            m_m6 = _m6;
        }

        inline uint32_t m6() const
        {
            return m_m6;
        }

        inline uint32_t& m6()
        {
            return m_m6;
        }
        inline void m7(uint32_t _m7)
        {
            m_m7 = _m7;
        }

        inline uint32_t m7() const
        {
            return m_m7;
        }

        inline uint32_t& m7()
        {
            return m_m7;
        }
        inline void m8(uint32_t _m8)
        {
            m_m8 = _m8;
        }

        inline uint32_t m8() const
        {
            return m_m8;
        }

        inline uint32_t& m8()
        {
            return m_m8;
        }
        inline void m9(uint32_t _m9)
        {
            m_m9 = _m9;
        }

        inline uint32_t m9() const
        {
            return m_m9;
        }

        inline uint32_t& m9()
        {
            return m_m9;
        }
        
    private:
        uint32_t m_m1;
        uint32_t m_m2;
        uint32_t m_m3;
        uint32_t m_m4;
        uint32_t m_m5;
        uint32_t m_m6;
        uint32_t m_m7;
        uint32_t m_m8;
        uint32_t m_m9;
    };
    class mfixed64s
    {
    public:
        mfixed64s();
        ~mfixed64s();
        mfixed64s(const mfixed64s &x);
        mfixed64s(mfixed64s &&x);
        mfixed64s& operator=(const mfixed64s &x);
        mfixed64s& operator=(mfixed64s &&x);
        
        inline void m1(uint64_t _m1)
        {
            m_m1 = _m1;
        }

        inline uint64_t m1() const
        {
            return m_m1;
        }

        inline uint64_t& m1()
        {
            return m_m1;
        }
        inline void m2(uint64_t _m2)
        {
            m_m2 = _m2;
        }

        inline uint64_t m2() const
        {
            return m_m2;
        }

        inline uint64_t& m2()
        {
            return m_m2;
        }
        inline void m3(uint64_t _m3)
        {
            m_m3 = _m3;
        }

        inline uint64_t m3() const
        {
            return m_m3;
        }

        inline uint64_t& m3()
        {
            return m_m3;
        }
        inline void m4(uint64_t _m4)
        {
            m_m4 = _m4;
        }

        inline uint64_t m4() const
        {
            return m_m4;
        }

        inline uint64_t& m4()
        {
            return m_m4;
        }
        inline void m5(uint64_t _m5)
        {
            m_m5 = _m5;
        }

        inline uint64_t m5() const
        {
            return m_m5;
        }

        inline uint64_t& m5()
        {
            return m_m5;
        }
        inline void m6(uint64_t _m6)
        {
            m_m6 = _m6;
        }

        inline uint64_t m6() const
        {
            return m_m6;
        }

        inline uint64_t& m6()
        {
            return m_m6;
        }
        inline void m7(uint64_t _m7)
        {
            m_m7 = _m7;
        }

        inline uint64_t m7() const
        {
            return m_m7;
        }

        inline uint64_t& m7()
        {
            return m_m7;
        }
        inline void m8(uint64_t _m8)
        {
            m_m8 = _m8;
        }

        inline uint64_t m8() const
        {
            return m_m8;
        }

        inline uint64_t& m8()
        {
            return m_m8;
        }
        inline void m9(uint64_t _m9)
        {
            m_m9 = _m9;
        }

        inline uint64_t m9() const
        {
            return m_m9;
        }

        inline uint64_t& m9()
        {
            return m_m9;
        }
        
    private:
        uint64_t m_m1;
        uint64_t m_m2;
        uint64_t m_m3;
        uint64_t m_m4;
        uint64_t m_m5;
        uint64_t m_m6;
        uint64_t m_m7;
        uint64_t m_m8;
        uint64_t m_m9;
    };
    class mstrings
    {
    public:
        mstrings();
        ~mstrings();
        mstrings(const mstrings &x);
        mstrings(mstrings &&x);
        mstrings& operator=(const mstrings &x);
        mstrings& operator=(mstrings &&x);
        
        inline void m1(const std::string &_m1)
        {
            m_m1 = _m1;
        }

        inline void m1(std::string &&_m1)
        {
            m_m1 = std::move(_m1);
        }

        inline const std::string& m1() const
        {
            return m_m1;
        }

        inline std::string& m1()
        {
            return m_m1;
        }
        inline void m2(const std::string &_m2)
        {
            m_m2 = _m2;
        }

        inline void m2(std::string &&_m2)
        {
            m_m2 = std::move(_m2);
        }

        inline const std::string& m2() const
        {
            return m_m2;
        }

        inline std::string& m2()
        {
            return m_m2;
        }
        inline void m3(const std::string &_m3)
        {
            m_m3 = _m3;
        }

        inline void m3(std::string &&_m3)
        {
            m_m3 = std::move(_m3);
        }

        inline const std::string& m3() const
        {
            return m_m3;
        }

        inline std::string& m3()
        {
            return m_m3;
        }
        inline void m4(const std::string &_m4)
        {
            m_m4 = _m4;
        }

        inline void m4(std::string &&_m4)
        {
            m_m4 = std::move(_m4);
        }

        inline const std::string& m4() const
        {
            return m_m4;
        }

        inline std::string& m4()
        {
            return m_m4;
        }
        inline void m5(const std::string &_m5)
        {
            m_m5 = _m5;
        }

        inline void m5(std::string &&_m5)
        {
            m_m5 = std::move(_m5);
        }

        inline const std::string& m5() const
        {
            return m_m5;
        }

        inline std::string& m5()
        {
            return m_m5;
        }
        inline void m6(const std::string &_m6)
        {
            m_m6 = _m6;
        }

        inline void m6(std::string &&_m6)
        {
            m_m6 = std::move(_m6);
        }

        inline const std::string& m6() const
        {
            return m_m6;
        }

        inline std::string& m6()
        {
            return m_m6;
        }
        inline void m7(const std::string &_m7)
        {
            m_m7 = _m7;
        }

        inline void m7(std::string &&_m7)
        {
            m_m7 = std::move(_m7);
        }

        inline const std::string& m7() const
        {
            return m_m7;
        }

        inline std::string& m7()
        {
            return m_m7;
        }
        inline void m8(const std::string &_m8)
        {
            m_m8 = _m8;
        }

        inline void m8(std::string &&_m8)
        {
            m_m8 = std::move(_m8);
        }

        inline const std::string& m8() const
        {
            return m_m8;
        }

        inline std::string& m8()
        {
            return m_m8;
        }
        inline void m9(const std::string &_m9)
        {
            m_m9 = _m9;
        }

        inline void m9(std::string &&_m9)
        {
            m_m9 = std::move(_m9);
        }

        inline const std::string& m9() const
        {
            return m_m9;
        }

        inline std::string& m9()
        {
            return m_m9;
        }
        
    private:
        std::string m_m1;
        std::string m_m2;
        std::string m_m3;
        std::string m_m4;
        std::string m_m5;
        std::string m_m6;
        std::string m_m7;
        std::string m_m8;
        std::string m_m9;
    };
    class Performance
    {
    public:
        Performance();
        ~Performance();
        Performance(const Performance &x);
        Performance(Performance &&x);
        Performance& operator=(const Performance &x);
        Performance& operator=(Performance &&x);
        
        inline void mf(const performance::mfloats &_mf)
        {
            m_mf = _mf;
        }

        inline void mf(performance::mfloats &&_mf)
        {
            m_mf = std::move(_mf);
        }

        inline const performance::mfloats& mf() const
        {
            return m_mf;
        }

        inline performance::mfloats& mf()
        {
            return m_mf;
        }
        inline void md(const performance::mdoubles &_md)
        {
            m_md = _md;
        }

        inline void md(performance::mdoubles &&_md)
        {
            m_md = std::move(_md);
        }

        inline const performance::mdoubles& md() const
        {
            return m_md;
        }

        inline performance::mdoubles& md()
        {
            return m_md;
        }
        inline void msf3(const performance::msfixed32s &_msf3)
        {
            m_msf3 = _msf3;
        }

        inline void msf3(performance::msfixed32s &&_msf3)
        {
            m_msf3 = std::move(_msf3);
        }

        inline const performance::msfixed32s& msf3() const
        {
            return m_msf3;
        }

        inline performance::msfixed32s& msf3()
        {
            return m_msf3;
        }
        inline void msf6(const performance::msfixed64s &_msf6)
        {
            m_msf6 = _msf6;
        }

        inline void msf6(performance::msfixed64s &&_msf6)
        {
            m_msf6 = std::move(_msf6);
        }

        inline const performance::msfixed64s& msf6() const
        {
            return m_msf6;
        }

        inline performance::msfixed64s& msf6()
        {
            return m_msf6;
        }
        inline void mf3(const performance::mfixed32s &_mf3)
        {
            m_mf3 = _mf3;
        }

        inline void mf3(performance::mfixed32s &&_mf3)
        {
            m_mf3 = std::move(_mf3);
        }

        inline const performance::mfixed32s& mf3() const
        {
            return m_mf3;
        }

        inline performance::mfixed32s& mf3()
        {
            return m_mf3;
        }
        inline void mf6(const performance::mfixed64s &_mf6)
        {
            m_mf6 = _mf6;
        }

        inline void mf6(performance::mfixed64s &&_mf6)
        {
            m_mf6 = std::move(_mf6);
        }

        inline const performance::mfixed64s& mf6() const
        {
            return m_mf6;
        }

        inline performance::mfixed64s& mf6()
        {
            return m_mf6;
        }
        inline void mstr(const performance::mstrings &_mstr)
        {
            m_mstr = _mstr;
        }

        inline void mstr(performance::mstrings &&_mstr)
        {
            m_mstr = std::move(_mstr);
        }

        inline const performance::mstrings& mstr() const
        {
            return m_mstr;
        }

        inline performance::mstrings& mstr()
        {
            return m_mstr;
        }
        
    private:
        performance::mfloats m_mf;
        performance::mdoubles m_md;
        performance::msfixed32s m_msf3;
        performance::msfixed64s m_msf6;
        performance::mfixed32s m_mf3;
        performance::mfixed64s m_mf6;
        performance::mstrings m_mstr;
    };
}

#endif // _Performance_H_