#ifndef _Performance_100_H_
#define _Performance_100_H_

#include <stdint.h>
#include <array>
#include <string>
#include <vector>

#if defined(WIN32)
#if defined(USER_CPP_DLL_EXPORT)
#define user_cpp_DllExport __declspec( dllexport )
#else
#define user_cpp_DllExport
#endif
#else
#define user_cpp_DllExport
#endif

namespace performance
{
    /*!
     * @brief This class represents the structure Performance defined by the user in the IDL file.
     */
    class user_cpp_DllExport Performance
    {
    public:

        /*!
         * @brief Default constructor.
         */
        Performance();
        
        /*!
         * @brief Default destructor.
         */
        ~Performance();
        
        /*!
         * @brief Copy constructor.
         * @param x Reference to the object performance::Performance that will be copied.
         */
        Performance(const Performance &x);
        
        /*!
         * @brief Move constructor.
         * @param x Reference to the object performance::Performance that will be copied.
         */
        Performance(Performance &&x);
        
        /*!
         * @brief Copy assignment.
         * @param x Reference to the object performance::Performance that will be copied.
         */
        Performance& operator=(const Performance &x);
        
        /*!
         * @brief Move assignment.
         * @param x Reference to the object performance::Performance that will be copied.
         */
        Performance& operator=(Performance &&x);
        
        /*!
         * @brief This function sets a value in member m1
         * @param _m1 New value for member m1
         */
        inline void m1(int32_t _m1)
        {
            m_m1 = _m1;
        }

        /*!
         * @brief This function returns the value of member m1
         * @return Value of member m1
         */
        inline int32_t m1() const
        {
            return m_m1;
        }

        /*!
         * @brief This function returns a reference to member m1
         * @return Reference to member m1
         */
        inline int32_t& m1()
        {
            return m_m1;
        }
        /*!
         * @brief This function sets a value in member m2
         * @param _m2 New value for member m2
         */
        inline void m2(int32_t _m2)
        {
            m_m2 = _m2;
        }

        /*!
         * @brief This function returns the value of member m2
         * @return Value of member m2
         */
        inline int32_t m2() const
        {
            return m_m2;
        }

        /*!
         * @brief This function returns a reference to member m2
         * @return Reference to member m2
         */
        inline int32_t& m2()
        {
            return m_m2;
        }
        /*!
         * @brief This function sets a value in member m3
         * @param _m3 New value for member m3
         */
        inline void m3(int32_t _m3)
        {
            m_m3 = _m3;
        }

        /*!
         * @brief This function returns the value of member m3
         * @return Value of member m3
         */
        inline int32_t m3() const
        {
            return m_m3;
        }

        /*!
         * @brief This function returns a reference to member m3
         * @return Reference to member m3
         */
        inline int32_t& m3()
        {
            return m_m3;
        }
        /*!
         * @brief This function sets a value in member m4
         * @param _m4 New value for member m4
         */
        inline void m4(int32_t _m4)
        {
            m_m4 = _m4;
        }

        /*!
         * @brief This function returns the value of member m4
         * @return Value of member m4
         */
        inline int32_t m4() const
        {
            return m_m4;
        }

        /*!
         * @brief This function returns a reference to member m4
         * @return Reference to member m4
         */
        inline int32_t& m4()
        {
            return m_m4;
        }
        /*!
         * @brief This function sets a value in member m5
         * @param _m5 New value for member m5
         */
        inline void m5(int32_t _m5)
        {
            m_m5 = _m5;
        }

        /*!
         * @brief This function returns the value of member m5
         * @return Value of member m5
         */
        inline int32_t m5() const
        {
            return m_m5;
        }

        /*!
         * @brief This function returns a reference to member m5
         * @return Reference to member m5
         */
        inline int32_t& m5()
        {
            return m_m5;
        }
        /*!
         * @brief This function sets a value in member m6
         * @param _m6 New value for member m6
         */
        inline void m6(int32_t _m6)
        {
            m_m6 = _m6;
        }

        /*!
         * @brief This function returns the value of member m6
         * @return Value of member m6
         */
        inline int32_t m6() const
        {
            return m_m6;
        }

        /*!
         * @brief This function returns a reference to member m6
         * @return Reference to member m6
         */
        inline int32_t& m6()
        {
            return m_m6;
        }
        /*!
         * @brief This function sets a value in member m7
         * @param _m7 New value for member m7
         */
        inline void m7(int32_t _m7)
        {
            m_m7 = _m7;
        }

        /*!
         * @brief This function returns the value of member m7
         * @return Value of member m7
         */
        inline int32_t m7() const
        {
            return m_m7;
        }

        /*!
         * @brief This function returns a reference to member m7
         * @return Reference to member m7
         */
        inline int32_t& m7()
        {
            return m_m7;
        }
        /*!
         * @brief This function sets a value in member m8
         * @param _m8 New value for member m8
         */
        inline void m8(int32_t _m8)
        {
            m_m8 = _m8;
        }

        /*!
         * @brief This function returns the value of member m8
         * @return Value of member m8
         */
        inline int32_t m8() const
        {
            return m_m8;
        }

        /*!
         * @brief This function returns a reference to member m8
         * @return Reference to member m8
         */
        inline int32_t& m8()
        {
            return m_m8;
        }
        /*!
         * @brief This function sets a value in member m9
         * @param _m9 New value for member m9
         */
        inline void m9(int32_t _m9)
        {
            m_m9 = _m9;
        }

        /*!
         * @brief This function returns the value of member m9
         * @return Value of member m9
         */
        inline int32_t m9() const
        {
            return m_m9;
        }

        /*!
         * @brief This function returns a reference to member m9
         * @return Reference to member m9
         */
        inline int32_t& m9()
        {
            return m_m9;
        }
        /*!
         * @brief This function sets a value in member m10
         * @param _m10 New value for member m10
         */
        inline void m10(int32_t _m10)
        {
            m_m10 = _m10;
        }

        /*!
         * @brief This function returns the value of member m10
         * @return Value of member m10
         */
        inline int32_t m10() const
        {
            return m_m10;
        }

        /*!
         * @brief This function returns a reference to member m10
         * @return Reference to member m10
         */
        inline int32_t& m10()
        {
            return m_m10;
        }
        /*!
         * @brief This function sets a value in member m11
         * @param _m11 New value for member m11
         */
        inline void m11(int32_t _m11)
        {
            m_m11 = _m11;
        }

        /*!
         * @brief This function returns the value of member m11
         * @return Value of member m11
         */
        inline int32_t m11() const
        {
            return m_m11;
        }

        /*!
         * @brief This function returns a reference to member m11
         * @return Reference to member m11
         */
        inline int32_t& m11()
        {
            return m_m11;
        }
        /*!
         * @brief This function sets a value in member m12
         * @param _m12 New value for member m12
         */
        inline void m12(int32_t _m12)
        {
            m_m12 = _m12;
        }

        /*!
         * @brief This function returns the value of member m12
         * @return Value of member m12
         */
        inline int32_t m12() const
        {
            return m_m12;
        }

        /*!
         * @brief This function returns a reference to member m12
         * @return Reference to member m12
         */
        inline int32_t& m12()
        {
            return m_m12;
        }
        /*!
         * @brief This function sets a value in member m13
         * @param _m13 New value for member m13
         */
        inline void m13(int32_t _m13)
        {
            m_m13 = _m13;
        }

        /*!
         * @brief This function returns the value of member m13
         * @return Value of member m13
         */
        inline int32_t m13() const
        {
            return m_m13;
        }

        /*!
         * @brief This function returns a reference to member m13
         * @return Reference to member m13
         */
        inline int32_t& m13()
        {
            return m_m13;
        }
        /*!
         * @brief This function sets a value in member m14
         * @param _m14 New value for member m14
         */
        inline void m14(int32_t _m14)
        {
            m_m14 = _m14;
        }

        /*!
         * @brief This function returns the value of member m14
         * @return Value of member m14
         */
        inline int32_t m14() const
        {
            return m_m14;
        }

        /*!
         * @brief This function returns a reference to member m14
         * @return Reference to member m14
         */
        inline int32_t& m14()
        {
            return m_m14;
        }
        /*!
         * @brief This function sets a value in member m15
         * @param _m15 New value for member m15
         */
        inline void m15(int32_t _m15)
        {
            m_m15 = _m15;
        }

        /*!
         * @brief This function returns the value of member m15
         * @return Value of member m15
         */
        inline int32_t m15() const
        {
            return m_m15;
        }

        /*!
         * @brief This function returns a reference to member m15
         * @return Reference to member m15
         */
        inline int32_t& m15()
        {
            return m_m15;
        }
        /*!
         * @brief This function sets a value in member m16
         * @param _m16 New value for member m16
         */
        inline void m16(int32_t _m16)
        {
            m_m16 = _m16;
        }

        /*!
         * @brief This function returns the value of member m16
         * @return Value of member m16
         */
        inline int32_t m16() const
        {
            return m_m16;
        }

        /*!
         * @brief This function returns a reference to member m16
         * @return Reference to member m16
         */
        inline int32_t& m16()
        {
            return m_m16;
        }
        /*!
         * @brief This function sets a value in member m17
         * @param _m17 New value for member m17
         */
        inline void m17(int32_t _m17)
        {
            m_m17 = _m17;
        }

        /*!
         * @brief This function returns the value of member m17
         * @return Value of member m17
         */
        inline int32_t m17() const
        {
            return m_m17;
        }

        /*!
         * @brief This function returns a reference to member m17
         * @return Reference to member m17
         */
        inline int32_t& m17()
        {
            return m_m17;
        }
        /*!
         * @brief This function sets a value in member m18
         * @param _m18 New value for member m18
         */
        inline void m18(int32_t _m18)
        {
            m_m18 = _m18;
        }

        /*!
         * @brief This function returns the value of member m18
         * @return Value of member m18
         */
        inline int32_t m18() const
        {
            return m_m18;
        }

        /*!
         * @brief This function returns a reference to member m18
         * @return Reference to member m18
         */
        inline int32_t& m18()
        {
            return m_m18;
        }
        /*!
         * @brief This function sets a value in member m19
         * @param _m19 New value for member m19
         */
        inline void m19(int32_t _m19)
        {
            m_m19 = _m19;
        }

        /*!
         * @brief This function returns the value of member m19
         * @return Value of member m19
         */
        inline int32_t m19() const
        {
            return m_m19;
        }

        /*!
         * @brief This function returns a reference to member m19
         * @return Reference to member m19
         */
        inline int32_t& m19()
        {
            return m_m19;
        }
        /*!
         * @brief This function sets a value in member m20
         * @param _m20 New value for member m20
         */
        inline void m20(int32_t _m20)
        {
            m_m20 = _m20;
        }

        /*!
         * @brief This function returns the value of member m20
         * @return Value of member m20
         */
        inline int32_t m20() const
        {
            return m_m20;
        }

        /*!
         * @brief This function returns a reference to member m20
         * @return Reference to member m20
         */
        inline int32_t& m20()
        {
            return m_m20;
        }
        /*!
         * @brief This function sets a value in member m21
         * @param _m21 New value for member m21
         */
        inline void m21(int32_t _m21)
        {
            m_m21 = _m21;
        }

        /*!
         * @brief This function returns the value of member m21
         * @return Value of member m21
         */
        inline int32_t m21() const
        {
            return m_m21;
        }

        /*!
         * @brief This function returns a reference to member m21
         * @return Reference to member m21
         */
        inline int32_t& m21()
        {
            return m_m21;
        }
        /*!
         * @brief This function sets a value in member m22
         * @param _m22 New value for member m22
         */
        inline void m22(int32_t _m22)
        {
            m_m22 = _m22;
        }

        /*!
         * @brief This function returns the value of member m22
         * @return Value of member m22
         */
        inline int32_t m22() const
        {
            return m_m22;
        }

        /*!
         * @brief This function returns a reference to member m22
         * @return Reference to member m22
         */
        inline int32_t& m22()
        {
            return m_m22;
        }
        /*!
         * @brief This function sets a value in member m23
         * @param _m23 New value for member m23
         */
        inline void m23(int32_t _m23)
        {
            m_m23 = _m23;
        }

        /*!
         * @brief This function returns the value of member m23
         * @return Value of member m23
         */
        inline int32_t m23() const
        {
            return m_m23;
        }

        /*!
         * @brief This function returns a reference to member m23
         * @return Reference to member m23
         */
        inline int32_t& m23()
        {
            return m_m23;
        }
        /*!
         * @brief This function sets a value in member m24
         * @param _m24 New value for member m24
         */
        inline void m24(int32_t _m24)
        {
            m_m24 = _m24;
        }

        /*!
         * @brief This function returns the value of member m24
         * @return Value of member m24
         */
        inline int32_t m24() const
        {
            return m_m24;
        }

        /*!
         * @brief This function returns a reference to member m24
         * @return Reference to member m24
         */
        inline int32_t& m24()
        {
            return m_m24;
        }
        /*!
         * @brief This function sets a value in member m25
         * @param _m25 New value for member m25
         */
        inline void m25(int32_t _m25)
        {
            m_m25 = _m25;
        }

        /*!
         * @brief This function returns the value of member m25
         * @return Value of member m25
         */
        inline int32_t m25() const
        {
            return m_m25;
        }

        /*!
         * @brief This function returns a reference to member m25
         * @return Reference to member m25
         */
        inline int32_t& m25()
        {
            return m_m25;
        }
        /*!
         * @brief This function sets a value in member m26
         * @param _m26 New value for member m26
         */
        inline void m26(int32_t _m26)
        {
            m_m26 = _m26;
        }

        /*!
         * @brief This function returns the value of member m26
         * @return Value of member m26
         */
        inline int32_t m26() const
        {
            return m_m26;
        }

        /*!
         * @brief This function returns a reference to member m26
         * @return Reference to member m26
         */
        inline int32_t& m26()
        {
            return m_m26;
        }
        /*!
         * @brief This function sets a value in member m27
         * @param _m27 New value for member m27
         */
        inline void m27(int32_t _m27)
        {
            m_m27 = _m27;
        }

        /*!
         * @brief This function returns the value of member m27
         * @return Value of member m27
         */
        inline int32_t m27() const
        {
            return m_m27;
        }

        /*!
         * @brief This function returns a reference to member m27
         * @return Reference to member m27
         */
        inline int32_t& m27()
        {
            return m_m27;
        }
        /*!
         * @brief This function sets a value in member m28
         * @param _m28 New value for member m28
         */
        inline void m28(int32_t _m28)
        {
            m_m28 = _m28;
        }

        /*!
         * @brief This function returns the value of member m28
         * @return Value of member m28
         */
        inline int32_t m28() const
        {
            return m_m28;
        }

        /*!
         * @brief This function returns a reference to member m28
         * @return Reference to member m28
         */
        inline int32_t& m28()
        {
            return m_m28;
        }
        /*!
         * @brief This function sets a value in member m29
         * @param _m29 New value for member m29
         */
        inline void m29(int32_t _m29)
        {
            m_m29 = _m29;
        }

        /*!
         * @brief This function returns the value of member m29
         * @return Value of member m29
         */
        inline int32_t m29() const
        {
            return m_m29;
        }

        /*!
         * @brief This function returns a reference to member m29
         * @return Reference to member m29
         */
        inline int32_t& m29()
        {
            return m_m29;
        }
        /*!
         * @brief This function sets a value in member m30
         * @param _m30 New value for member m30
         */
        inline void m30(int32_t _m30)
        {
            m_m30 = _m30;
        }

        /*!
         * @brief This function returns the value of member m30
         * @return Value of member m30
         */
        inline int32_t m30() const
        {
            return m_m30;
        }

        /*!
         * @brief This function returns a reference to member m30
         * @return Reference to member m30
         */
        inline int32_t& m30()
        {
            return m_m30;
        }
        /*!
         * @brief This function sets a value in member m31
         * @param _m31 New value for member m31
         */
        inline void m31(int32_t _m31)
        {
            m_m31 = _m31;
        }

        /*!
         * @brief This function returns the value of member m31
         * @return Value of member m31
         */
        inline int32_t m31() const
        {
            return m_m31;
        }

        /*!
         * @brief This function returns a reference to member m31
         * @return Reference to member m31
         */
        inline int32_t& m31()
        {
            return m_m31;
        }
        /*!
         * @brief This function sets a value in member m32
         * @param _m32 New value for member m32
         */
        inline void m32(int32_t _m32)
        {
            m_m32 = _m32;
        }

        /*!
         * @brief This function returns the value of member m32
         * @return Value of member m32
         */
        inline int32_t m32() const
        {
            return m_m32;
        }

        /*!
         * @brief This function returns a reference to member m32
         * @return Reference to member m32
         */
        inline int32_t& m32()
        {
            return m_m32;
        }
        /*!
         * @brief This function sets a value in member m33
         * @param _m33 New value for member m33
         */
        inline void m33(int32_t _m33)
        {
            m_m33 = _m33;
        }

        /*!
         * @brief This function returns the value of member m33
         * @return Value of member m33
         */
        inline int32_t m33() const
        {
            return m_m33;
        }

        /*!
         * @brief This function returns a reference to member m33
         * @return Reference to member m33
         */
        inline int32_t& m33()
        {
            return m_m33;
        }
        /*!
         * @brief This function sets a value in member m34
         * @param _m34 New value for member m34
         */
        inline void m34(int32_t _m34)
        {
            m_m34 = _m34;
        }

        /*!
         * @brief This function returns the value of member m34
         * @return Value of member m34
         */
        inline int32_t m34() const
        {
            return m_m34;
        }

        /*!
         * @brief This function returns a reference to member m34
         * @return Reference to member m34
         */
        inline int32_t& m34()
        {
            return m_m34;
        }
        /*!
         * @brief This function sets a value in member m35
         * @param _m35 New value for member m35
         */
        inline void m35(int32_t _m35)
        {
            m_m35 = _m35;
        }

        /*!
         * @brief This function returns the value of member m35
         * @return Value of member m35
         */
        inline int32_t m35() const
        {
            return m_m35;
        }

        /*!
         * @brief This function returns a reference to member m35
         * @return Reference to member m35
         */
        inline int32_t& m35()
        {
            return m_m35;
        }
        /*!
         * @brief This function sets a value in member m36
         * @param _m36 New value for member m36
         */
        inline void m36(int32_t _m36)
        {
            m_m36 = _m36;
        }

        /*!
         * @brief This function returns the value of member m36
         * @return Value of member m36
         */
        inline int32_t m36() const
        {
            return m_m36;
        }

        /*!
         * @brief This function returns a reference to member m36
         * @return Reference to member m36
         */
        inline int32_t& m36()
        {
            return m_m36;
        }
        /*!
         * @brief This function sets a value in member m37
         * @param _m37 New value for member m37
         */
        inline void m37(int32_t _m37)
        {
            m_m37 = _m37;
        }

        /*!
         * @brief This function returns the value of member m37
         * @return Value of member m37
         */
        inline int32_t m37() const
        {
            return m_m37;
        }

        /*!
         * @brief This function returns a reference to member m37
         * @return Reference to member m37
         */
        inline int32_t& m37()
        {
            return m_m37;
        }
        /*!
         * @brief This function sets a value in member m38
         * @param _m38 New value for member m38
         */
        inline void m38(int32_t _m38)
        {
            m_m38 = _m38;
        }

        /*!
         * @brief This function returns the value of member m38
         * @return Value of member m38
         */
        inline int32_t m38() const
        {
            return m_m38;
        }

        /*!
         * @brief This function returns a reference to member m38
         * @return Reference to member m38
         */
        inline int32_t& m38()
        {
            return m_m38;
        }
        /*!
         * @brief This function sets a value in member m39
         * @param _m39 New value for member m39
         */
        inline void m39(int32_t _m39)
        {
            m_m39 = _m39;
        }

        /*!
         * @brief This function returns the value of member m39
         * @return Value of member m39
         */
        inline int32_t m39() const
        {
            return m_m39;
        }

        /*!
         * @brief This function returns a reference to member m39
         * @return Reference to member m39
         */
        inline int32_t& m39()
        {
            return m_m39;
        }
        /*!
         * @brief This function sets a value in member m40
         * @param _m40 New value for member m40
         */
        inline void m40(int32_t _m40)
        {
            m_m40 = _m40;
        }

        /*!
         * @brief This function returns the value of member m40
         * @return Value of member m40
         */
        inline int32_t m40() const
        {
            return m_m40;
        }

        /*!
         * @brief This function returns a reference to member m40
         * @return Reference to member m40
         */
        inline int32_t& m40()
        {
            return m_m40;
        }
        /*!
         * @brief This function sets a value in member m41
         * @param _m41 New value for member m41
         */
        inline void m41(int32_t _m41)
        {
            m_m41 = _m41;
        }

        /*!
         * @brief This function returns the value of member m41
         * @return Value of member m41
         */
        inline int32_t m41() const
        {
            return m_m41;
        }

        /*!
         * @brief This function returns a reference to member m41
         * @return Reference to member m41
         */
        inline int32_t& m41()
        {
            return m_m41;
        }
        /*!
         * @brief This function sets a value in member m42
         * @param _m42 New value for member m42
         */
        inline void m42(int32_t _m42)
        {
            m_m42 = _m42;
        }

        /*!
         * @brief This function returns the value of member m42
         * @return Value of member m42
         */
        inline int32_t m42() const
        {
            return m_m42;
        }

        /*!
         * @brief This function returns a reference to member m42
         * @return Reference to member m42
         */
        inline int32_t& m42()
        {
            return m_m42;
        }
        /*!
         * @brief This function sets a value in member m43
         * @param _m43 New value for member m43
         */
        inline void m43(int32_t _m43)
        {
            m_m43 = _m43;
        }

        /*!
         * @brief This function returns the value of member m43
         * @return Value of member m43
         */
        inline int32_t m43() const
        {
            return m_m43;
        }

        /*!
         * @brief This function returns a reference to member m43
         * @return Reference to member m43
         */
        inline int32_t& m43()
        {
            return m_m43;
        }
        /*!
         * @brief This function sets a value in member m44
         * @param _m44 New value for member m44
         */
        inline void m44(int32_t _m44)
        {
            m_m44 = _m44;
        }

        /*!
         * @brief This function returns the value of member m44
         * @return Value of member m44
         */
        inline int32_t m44() const
        {
            return m_m44;
        }

        /*!
         * @brief This function returns a reference to member m44
         * @return Reference to member m44
         */
        inline int32_t& m44()
        {
            return m_m44;
        }
        /*!
         * @brief This function sets a value in member m45
         * @param _m45 New value for member m45
         */
        inline void m45(int32_t _m45)
        {
            m_m45 = _m45;
        }

        /*!
         * @brief This function returns the value of member m45
         * @return Value of member m45
         */
        inline int32_t m45() const
        {
            return m_m45;
        }

        /*!
         * @brief This function returns a reference to member m45
         * @return Reference to member m45
         */
        inline int32_t& m45()
        {
            return m_m45;
        }
        /*!
         * @brief This function sets a value in member m46
         * @param _m46 New value for member m46
         */
        inline void m46(int32_t _m46)
        {
            m_m46 = _m46;
        }

        /*!
         * @brief This function returns the value of member m46
         * @return Value of member m46
         */
        inline int32_t m46() const
        {
            return m_m46;
        }

        /*!
         * @brief This function returns a reference to member m46
         * @return Reference to member m46
         */
        inline int32_t& m46()
        {
            return m_m46;
        }
        /*!
         * @brief This function sets a value in member m47
         * @param _m47 New value for member m47
         */
        inline void m47(int32_t _m47)
        {
            m_m47 = _m47;
        }

        /*!
         * @brief This function returns the value of member m47
         * @return Value of member m47
         */
        inline int32_t m47() const
        {
            return m_m47;
        }

        /*!
         * @brief This function returns a reference to member m47
         * @return Reference to member m47
         */
        inline int32_t& m47()
        {
            return m_m47;
        }
        /*!
         * @brief This function sets a value in member m48
         * @param _m48 New value for member m48
         */
        inline void m48(int32_t _m48)
        {
            m_m48 = _m48;
        }

        /*!
         * @brief This function returns the value of member m48
         * @return Value of member m48
         */
        inline int32_t m48() const
        {
            return m_m48;
        }

        /*!
         * @brief This function returns a reference to member m48
         * @return Reference to member m48
         */
        inline int32_t& m48()
        {
            return m_m48;
        }
        /*!
         * @brief This function sets a value in member m49
         * @param _m49 New value for member m49
         */
        inline void m49(int32_t _m49)
        {
            m_m49 = _m49;
        }

        /*!
         * @brief This function returns the value of member m49
         * @return Value of member m49
         */
        inline int32_t m49() const
        {
            return m_m49;
        }

        /*!
         * @brief This function returns a reference to member m49
         * @return Reference to member m49
         */
        inline int32_t& m49()
        {
            return m_m49;
        }
        /*!
         * @brief This function sets a value in member m50
         * @param _m50 New value for member m50
         */
        inline void m50(int32_t _m50)
        {
            m_m50 = _m50;
        }

        /*!
         * @brief This function returns the value of member m50
         * @return Value of member m50
         */
        inline int32_t m50() const
        {
            return m_m50;
        }

        /*!
         * @brief This function returns a reference to member m50
         * @return Reference to member m50
         */
        inline int32_t& m50()
        {
            return m_m50;
        }
        /*!
         * @brief This function sets a value in member m51
         * @param _m51 New value for member m51
         */
        inline void m51(int32_t _m51)
        {
            m_m51 = _m51;
        }

        /*!
         * @brief This function returns the value of member m51
         * @return Value of member m51
         */
        inline int32_t m51() const
        {
            return m_m51;
        }

        /*!
         * @brief This function returns a reference to member m51
         * @return Reference to member m51
         */
        inline int32_t& m51()
        {
            return m_m51;
        }
        /*!
         * @brief This function sets a value in member m52
         * @param _m52 New value for member m52
         */
        inline void m52(int32_t _m52)
        {
            m_m52 = _m52;
        }

        /*!
         * @brief This function returns the value of member m52
         * @return Value of member m52
         */
        inline int32_t m52() const
        {
            return m_m52;
        }

        /*!
         * @brief This function returns a reference to member m52
         * @return Reference to member m52
         */
        inline int32_t& m52()
        {
            return m_m52;
        }
        /*!
         * @brief This function sets a value in member m53
         * @param _m53 New value for member m53
         */
        inline void m53(int32_t _m53)
        {
            m_m53 = _m53;
        }

        /*!
         * @brief This function returns the value of member m53
         * @return Value of member m53
         */
        inline int32_t m53() const
        {
            return m_m53;
        }

        /*!
         * @brief This function returns a reference to member m53
         * @return Reference to member m53
         */
        inline int32_t& m53()
        {
            return m_m53;
        }
        /*!
         * @brief This function sets a value in member m54
         * @param _m54 New value for member m54
         */
        inline void m54(int32_t _m54)
        {
            m_m54 = _m54;
        }

        /*!
         * @brief This function returns the value of member m54
         * @return Value of member m54
         */
        inline int32_t m54() const
        {
            return m_m54;
        }

        /*!
         * @brief This function returns a reference to member m54
         * @return Reference to member m54
         */
        inline int32_t& m54()
        {
            return m_m54;
        }
        /*!
         * @brief This function sets a value in member m55
         * @param _m55 New value for member m55
         */
        inline void m55(int32_t _m55)
        {
            m_m55 = _m55;
        }

        /*!
         * @brief This function returns the value of member m55
         * @return Value of member m55
         */
        inline int32_t m55() const
        {
            return m_m55;
        }

        /*!
         * @brief This function returns a reference to member m55
         * @return Reference to member m55
         */
        inline int32_t& m55()
        {
            return m_m55;
        }
        /*!
         * @brief This function sets a value in member m56
         * @param _m56 New value for member m56
         */
        inline void m56(int32_t _m56)
        {
            m_m56 = _m56;
        }

        /*!
         * @brief This function returns the value of member m56
         * @return Value of member m56
         */
        inline int32_t m56() const
        {
            return m_m56;
        }

        /*!
         * @brief This function returns a reference to member m56
         * @return Reference to member m56
         */
        inline int32_t& m56()
        {
            return m_m56;
        }
        /*!
         * @brief This function sets a value in member m57
         * @param _m57 New value for member m57
         */
        inline void m57(int32_t _m57)
        {
            m_m57 = _m57;
        }

        /*!
         * @brief This function returns the value of member m57
         * @return Value of member m57
         */
        inline int32_t m57() const
        {
            return m_m57;
        }

        /*!
         * @brief This function returns a reference to member m57
         * @return Reference to member m57
         */
        inline int32_t& m57()
        {
            return m_m57;
        }
        /*!
         * @brief This function sets a value in member m58
         * @param _m58 New value for member m58
         */
        inline void m58(int32_t _m58)
        {
            m_m58 = _m58;
        }

        /*!
         * @brief This function returns the value of member m58
         * @return Value of member m58
         */
        inline int32_t m58() const
        {
            return m_m58;
        }

        /*!
         * @brief This function returns a reference to member m58
         * @return Reference to member m58
         */
        inline int32_t& m58()
        {
            return m_m58;
        }
        /*!
         * @brief This function sets a value in member m59
         * @param _m59 New value for member m59
         */
        inline void m59(int32_t _m59)
        {
            m_m59 = _m59;
        }

        /*!
         * @brief This function returns the value of member m59
         * @return Value of member m59
         */
        inline int32_t m59() const
        {
            return m_m59;
        }

        /*!
         * @brief This function returns a reference to member m59
         * @return Reference to member m59
         */
        inline int32_t& m59()
        {
            return m_m59;
        }
        /*!
         * @brief This function sets a value in member m60
         * @param _m60 New value for member m60
         */
        inline void m60(int32_t _m60)
        {
            m_m60 = _m60;
        }

        /*!
         * @brief This function returns the value of member m60
         * @return Value of member m60
         */
        inline int32_t m60() const
        {
            return m_m60;
        }

        /*!
         * @brief This function returns a reference to member m60
         * @return Reference to member m60
         */
        inline int32_t& m60()
        {
            return m_m60;
        }
        /*!
         * @brief This function sets a value in member m61
         * @param _m61 New value for member m61
         */
        inline void m61(int32_t _m61)
        {
            m_m61 = _m61;
        }

        /*!
         * @brief This function returns the value of member m61
         * @return Value of member m61
         */
        inline int32_t m61() const
        {
            return m_m61;
        }

        /*!
         * @brief This function returns a reference to member m61
         * @return Reference to member m61
         */
        inline int32_t& m61()
        {
            return m_m61;
        }
        /*!
         * @brief This function sets a value in member m62
         * @param _m62 New value for member m62
         */
        inline void m62(int32_t _m62)
        {
            m_m62 = _m62;
        }

        /*!
         * @brief This function returns the value of member m62
         * @return Value of member m62
         */
        inline int32_t m62() const
        {
            return m_m62;
        }

        /*!
         * @brief This function returns a reference to member m62
         * @return Reference to member m62
         */
        inline int32_t& m62()
        {
            return m_m62;
        }
        /*!
         * @brief This function sets a value in member m63
         * @param _m63 New value for member m63
         */
        inline void m63(int32_t _m63)
        {
            m_m63 = _m63;
        }

        /*!
         * @brief This function returns the value of member m63
         * @return Value of member m63
         */
        inline int32_t m63() const
        {
            return m_m63;
        }

        /*!
         * @brief This function returns a reference to member m63
         * @return Reference to member m63
         */
        inline int32_t& m63()
        {
            return m_m63;
        }
        /*!
         * @brief This function sets a value in member m64
         * @param _m64 New value for member m64
         */
        inline void m64(int32_t _m64)
        {
            m_m64 = _m64;
        }

        /*!
         * @brief This function returns the value of member m64
         * @return Value of member m64
         */
        inline int32_t m64() const
        {
            return m_m64;
        }

        /*!
         * @brief This function returns a reference to member m64
         * @return Reference to member m64
         */
        inline int32_t& m64()
        {
            return m_m64;
        }
        /*!
         * @brief This function sets a value in member m65
         * @param _m65 New value for member m65
         */
        inline void m65(int32_t _m65)
        {
            m_m65 = _m65;
        }

        /*!
         * @brief This function returns the value of member m65
         * @return Value of member m65
         */
        inline int32_t m65() const
        {
            return m_m65;
        }

        /*!
         * @brief This function returns a reference to member m65
         * @return Reference to member m65
         */
        inline int32_t& m65()
        {
            return m_m65;
        }
        /*!
         * @brief This function sets a value in member m66
         * @param _m66 New value for member m66
         */
        inline void m66(int32_t _m66)
        {
            m_m66 = _m66;
        }

        /*!
         * @brief This function returns the value of member m66
         * @return Value of member m66
         */
        inline int32_t m66() const
        {
            return m_m66;
        }

        /*!
         * @brief This function returns a reference to member m66
         * @return Reference to member m66
         */
        inline int32_t& m66()
        {
            return m_m66;
        }
        /*!
         * @brief This function sets a value in member m67
         * @param _m67 New value for member m67
         */
        inline void m67(int32_t _m67)
        {
            m_m67 = _m67;
        }

        /*!
         * @brief This function returns the value of member m67
         * @return Value of member m67
         */
        inline int32_t m67() const
        {
            return m_m67;
        }

        /*!
         * @brief This function returns a reference to member m67
         * @return Reference to member m67
         */
        inline int32_t& m67()
        {
            return m_m67;
        }
        /*!
         * @brief This function sets a value in member m68
         * @param _m68 New value for member m68
         */
        inline void m68(int32_t _m68)
        {
            m_m68 = _m68;
        }

        /*!
         * @brief This function returns the value of member m68
         * @return Value of member m68
         */
        inline int32_t m68() const
        {
            return m_m68;
        }

        /*!
         * @brief This function returns a reference to member m68
         * @return Reference to member m68
         */
        inline int32_t& m68()
        {
            return m_m68;
        }
        /*!
         * @brief This function sets a value in member m69
         * @param _m69 New value for member m69
         */
        inline void m69(int32_t _m69)
        {
            m_m69 = _m69;
        }

        /*!
         * @brief This function returns the value of member m69
         * @return Value of member m69
         */
        inline int32_t m69() const
        {
            return m_m69;
        }

        /*!
         * @brief This function returns a reference to member m69
         * @return Reference to member m69
         */
        inline int32_t& m69()
        {
            return m_m69;
        }
        /*!
         * @brief This function sets a value in member m70
         * @param _m70 New value for member m70
         */
        inline void m70(int32_t _m70)
        {
            m_m70 = _m70;
        }

        /*!
         * @brief This function returns the value of member m70
         * @return Value of member m70
         */
        inline int32_t m70() const
        {
            return m_m70;
        }

        /*!
         * @brief This function returns a reference to member m70
         * @return Reference to member m70
         */
        inline int32_t& m70()
        {
            return m_m70;
        }
        /*!
         * @brief This function sets a value in member m71
         * @param _m71 New value for member m71
         */
        inline void m71(int32_t _m71)
        {
            m_m71 = _m71;
        }

        /*!
         * @brief This function returns the value of member m71
         * @return Value of member m71
         */
        inline int32_t m71() const
        {
            return m_m71;
        }

        /*!
         * @brief This function returns a reference to member m71
         * @return Reference to member m71
         */
        inline int32_t& m71()
        {
            return m_m71;
        }
        /*!
         * @brief This function sets a value in member m72
         * @param _m72 New value for member m72
         */
        inline void m72(int32_t _m72)
        {
            m_m72 = _m72;
        }

        /*!
         * @brief This function returns the value of member m72
         * @return Value of member m72
         */
        inline int32_t m72() const
        {
            return m_m72;
        }

        /*!
         * @brief This function returns a reference to member m72
         * @return Reference to member m72
         */
        inline int32_t& m72()
        {
            return m_m72;
        }
        /*!
         * @brief This function sets a value in member m73
         * @param _m73 New value for member m73
         */
        inline void m73(int32_t _m73)
        {
            m_m73 = _m73;
        }

        /*!
         * @brief This function returns the value of member m73
         * @return Value of member m73
         */
        inline int32_t m73() const
        {
            return m_m73;
        }

        /*!
         * @brief This function returns a reference to member m73
         * @return Reference to member m73
         */
        inline int32_t& m73()
        {
            return m_m73;
        }
        /*!
         * @brief This function sets a value in member m74
         * @param _m74 New value for member m74
         */
        inline void m74(int32_t _m74)
        {
            m_m74 = _m74;
        }

        /*!
         * @brief This function returns the value of member m74
         * @return Value of member m74
         */
        inline int32_t m74() const
        {
            return m_m74;
        }

        /*!
         * @brief This function returns a reference to member m74
         * @return Reference to member m74
         */
        inline int32_t& m74()
        {
            return m_m74;
        }
        /*!
         * @brief This function sets a value in member m75
         * @param _m75 New value for member m75
         */
        inline void m75(int32_t _m75)
        {
            m_m75 = _m75;
        }

        /*!
         * @brief This function returns the value of member m75
         * @return Value of member m75
         */
        inline int32_t m75() const
        {
            return m_m75;
        }

        /*!
         * @brief This function returns a reference to member m75
         * @return Reference to member m75
         */
        inline int32_t& m75()
        {
            return m_m75;
        }
        /*!
         * @brief This function sets a value in member m76
         * @param _m76 New value for member m76
         */
        inline void m76(int32_t _m76)
        {
            m_m76 = _m76;
        }

        /*!
         * @brief This function returns the value of member m76
         * @return Value of member m76
         */
        inline int32_t m76() const
        {
            return m_m76;
        }

        /*!
         * @brief This function returns a reference to member m76
         * @return Reference to member m76
         */
        inline int32_t& m76()
        {
            return m_m76;
        }
        /*!
         * @brief This function sets a value in member m77
         * @param _m77 New value for member m77
         */
        inline void m77(int32_t _m77)
        {
            m_m77 = _m77;
        }

        /*!
         * @brief This function returns the value of member m77
         * @return Value of member m77
         */
        inline int32_t m77() const
        {
            return m_m77;
        }

        /*!
         * @brief This function returns a reference to member m77
         * @return Reference to member m77
         */
        inline int32_t& m77()
        {
            return m_m77;
        }
        /*!
         * @brief This function sets a value in member m78
         * @param _m78 New value for member m78
         */
        inline void m78(int32_t _m78)
        {
            m_m78 = _m78;
        }

        /*!
         * @brief This function returns the value of member m78
         * @return Value of member m78
         */
        inline int32_t m78() const
        {
            return m_m78;
        }

        /*!
         * @brief This function returns a reference to member m78
         * @return Reference to member m78
         */
        inline int32_t& m78()
        {
            return m_m78;
        }
        /*!
         * @brief This function sets a value in member m79
         * @param _m79 New value for member m79
         */
        inline void m79(int32_t _m79)
        {
            m_m79 = _m79;
        }

        /*!
         * @brief This function returns the value of member m79
         * @return Value of member m79
         */
        inline int32_t m79() const
        {
            return m_m79;
        }

        /*!
         * @brief This function returns a reference to member m79
         * @return Reference to member m79
         */
        inline int32_t& m79()
        {
            return m_m79;
        }
        /*!
         * @brief This function sets a value in member m80
         * @param _m80 New value for member m80
         */
        inline void m80(int32_t _m80)
        {
            m_m80 = _m80;
        }

        /*!
         * @brief This function returns the value of member m80
         * @return Value of member m80
         */
        inline int32_t m80() const
        {
            return m_m80;
        }

        /*!
         * @brief This function returns a reference to member m80
         * @return Reference to member m80
         */
        inline int32_t& m80()
        {
            return m_m80;
        }
        /*!
         * @brief This function sets a value in member m81
         * @param _m81 New value for member m81
         */
        inline void m81(int32_t _m81)
        {
            m_m81 = _m81;
        }

        /*!
         * @brief This function returns the value of member m81
         * @return Value of member m81
         */
        inline int32_t m81() const
        {
            return m_m81;
        }

        /*!
         * @brief This function returns a reference to member m81
         * @return Reference to member m81
         */
        inline int32_t& m81()
        {
            return m_m81;
        }
        /*!
         * @brief This function sets a value in member m82
         * @param _m82 New value for member m82
         */
        inline void m82(int32_t _m82)
        {
            m_m82 = _m82;
        }

        /*!
         * @brief This function returns the value of member m82
         * @return Value of member m82
         */
        inline int32_t m82() const
        {
            return m_m82;
        }

        /*!
         * @brief This function returns a reference to member m82
         * @return Reference to member m82
         */
        inline int32_t& m82()
        {
            return m_m82;
        }
        /*!
         * @brief This function sets a value in member m83
         * @param _m83 New value for member m83
         */
        inline void m83(int32_t _m83)
        {
            m_m83 = _m83;
        }

        /*!
         * @brief This function returns the value of member m83
         * @return Value of member m83
         */
        inline int32_t m83() const
        {
            return m_m83;
        }

        /*!
         * @brief This function returns a reference to member m83
         * @return Reference to member m83
         */
        inline int32_t& m83()
        {
            return m_m83;
        }
        /*!
         * @brief This function sets a value in member m84
         * @param _m84 New value for member m84
         */
        inline void m84(int32_t _m84)
        {
            m_m84 = _m84;
        }

        /*!
         * @brief This function returns the value of member m84
         * @return Value of member m84
         */
        inline int32_t m84() const
        {
            return m_m84;
        }

        /*!
         * @brief This function returns a reference to member m84
         * @return Reference to member m84
         */
        inline int32_t& m84()
        {
            return m_m84;
        }
        /*!
         * @brief This function sets a value in member m85
         * @param _m85 New value for member m85
         */
        inline void m85(int32_t _m85)
        {
            m_m85 = _m85;
        }

        /*!
         * @brief This function returns the value of member m85
         * @return Value of member m85
         */
        inline int32_t m85() const
        {
            return m_m85;
        }

        /*!
         * @brief This function returns a reference to member m85
         * @return Reference to member m85
         */
        inline int32_t& m85()
        {
            return m_m85;
        }
        /*!
         * @brief This function sets a value in member m86
         * @param _m86 New value for member m86
         */
        inline void m86(int32_t _m86)
        {
            m_m86 = _m86;
        }

        /*!
         * @brief This function returns the value of member m86
         * @return Value of member m86
         */
        inline int32_t m86() const
        {
            return m_m86;
        }

        /*!
         * @brief This function returns a reference to member m86
         * @return Reference to member m86
         */
        inline int32_t& m86()
        {
            return m_m86;
        }
        /*!
         * @brief This function sets a value in member m87
         * @param _m87 New value for member m87
         */
        inline void m87(int32_t _m87)
        {
            m_m87 = _m87;
        }

        /*!
         * @brief This function returns the value of member m87
         * @return Value of member m87
         */
        inline int32_t m87() const
        {
            return m_m87;
        }

        /*!
         * @brief This function returns a reference to member m87
         * @return Reference to member m87
         */
        inline int32_t& m87()
        {
            return m_m87;
        }
        /*!
         * @brief This function sets a value in member m88
         * @param _m88 New value for member m88
         */
        inline void m88(int32_t _m88)
        {
            m_m88 = _m88;
        }

        /*!
         * @brief This function returns the value of member m88
         * @return Value of member m88
         */
        inline int32_t m88() const
        {
            return m_m88;
        }

        /*!
         * @brief This function returns a reference to member m88
         * @return Reference to member m88
         */
        inline int32_t& m88()
        {
            return m_m88;
        }
        /*!
         * @brief This function sets a value in member m89
         * @param _m89 New value for member m89
         */
        inline void m89(int32_t _m89)
        {
            m_m89 = _m89;
        }

        /*!
         * @brief This function returns the value of member m89
         * @return Value of member m89
         */
        inline int32_t m89() const
        {
            return m_m89;
        }

        /*!
         * @brief This function returns a reference to member m89
         * @return Reference to member m89
         */
        inline int32_t& m89()
        {
            return m_m89;
        }
        /*!
         * @brief This function sets a value in member m90
         * @param _m90 New value for member m90
         */
        inline void m90(int32_t _m90)
        {
            m_m90 = _m90;
        }

        /*!
         * @brief This function returns the value of member m90
         * @return Value of member m90
         */
        inline int32_t m90() const
        {
            return m_m90;
        }

        /*!
         * @brief This function returns a reference to member m90
         * @return Reference to member m90
         */
        inline int32_t& m90()
        {
            return m_m90;
        }
        /*!
         * @brief This function sets a value in member m91
         * @param _m91 New value for member m91
         */
        inline void m91(int32_t _m91)
        {
            m_m91 = _m91;
        }

        /*!
         * @brief This function returns the value of member m91
         * @return Value of member m91
         */
        inline int32_t m91() const
        {
            return m_m91;
        }

        /*!
         * @brief This function returns a reference to member m91
         * @return Reference to member m91
         */
        inline int32_t& m91()
        {
            return m_m91;
        }
        /*!
         * @brief This function sets a value in member m92
         * @param _m92 New value for member m92
         */
        inline void m92(int32_t _m92)
        {
            m_m92 = _m92;
        }

        /*!
         * @brief This function returns the value of member m92
         * @return Value of member m92
         */
        inline int32_t m92() const
        {
            return m_m92;
        }

        /*!
         * @brief This function returns a reference to member m92
         * @return Reference to member m92
         */
        inline int32_t& m92()
        {
            return m_m92;
        }
        /*!
         * @brief This function sets a value in member m93
         * @param _m93 New value for member m93
         */
        inline void m93(int32_t _m93)
        {
            m_m93 = _m93;
        }

        /*!
         * @brief This function returns the value of member m93
         * @return Value of member m93
         */
        inline int32_t m93() const
        {
            return m_m93;
        }

        /*!
         * @brief This function returns a reference to member m93
         * @return Reference to member m93
         */
        inline int32_t& m93()
        {
            return m_m93;
        }
        /*!
         * @brief This function sets a value in member m94
         * @param _m94 New value for member m94
         */
        inline void m94(int32_t _m94)
        {
            m_m94 = _m94;
        }

        /*!
         * @brief This function returns the value of member m94
         * @return Value of member m94
         */
        inline int32_t m94() const
        {
            return m_m94;
        }

        /*!
         * @brief This function returns a reference to member m94
         * @return Reference to member m94
         */
        inline int32_t& m94()
        {
            return m_m94;
        }
        /*!
         * @brief This function sets a value in member m95
         * @param _m95 New value for member m95
         */
        inline void m95(int32_t _m95)
        {
            m_m95 = _m95;
        }

        /*!
         * @brief This function returns the value of member m95
         * @return Value of member m95
         */
        inline int32_t m95() const
        {
            return m_m95;
        }

        /*!
         * @brief This function returns a reference to member m95
         * @return Reference to member m95
         */
        inline int32_t& m95()
        {
            return m_m95;
        }
        /*!
         * @brief This function sets a value in member m96
         * @param _m96 New value for member m96
         */
        inline void m96(int32_t _m96)
        {
            m_m96 = _m96;
        }

        /*!
         * @brief This function returns the value of member m96
         * @return Value of member m96
         */
        inline int32_t m96() const
        {
            return m_m96;
        }

        /*!
         * @brief This function returns a reference to member m96
         * @return Reference to member m96
         */
        inline int32_t& m96()
        {
            return m_m96;
        }
        /*!
         * @brief This function sets a value in member m97
         * @param _m97 New value for member m97
         */
        inline void m97(int32_t _m97)
        {
            m_m97 = _m97;
        }

        /*!
         * @brief This function returns the value of member m97
         * @return Value of member m97
         */
        inline int32_t m97() const
        {
            return m_m97;
        }

        /*!
         * @brief This function returns a reference to member m97
         * @return Reference to member m97
         */
        inline int32_t& m97()
        {
            return m_m97;
        }
        /*!
         * @brief This function sets a value in member m98
         * @param _m98 New value for member m98
         */
        inline void m98(int32_t _m98)
        {
            m_m98 = _m98;
        }

        /*!
         * @brief This function returns the value of member m98
         * @return Value of member m98
         */
        inline int32_t m98() const
        {
            return m_m98;
        }

        /*!
         * @brief This function returns a reference to member m98
         * @return Reference to member m98
         */
        inline int32_t& m98()
        {
            return m_m98;
        }
        /*!
         * @brief This function sets a value in member m99
         * @param _m99 New value for member m99
         */
        inline void m99(int32_t _m99)
        {
            m_m99 = _m99;
        }

        /*!
         * @brief This function returns the value of member m99
         * @return Value of member m99
         */
        inline int32_t m99() const
        {
            return m_m99;
        }

        /*!
         * @brief This function returns a reference to member m99
         * @return Reference to member m99
         */
        inline int32_t& m99()
        {
            return m_m99;
        }
        /*!
         * @brief This function sets a value in member m100
         * @param _m100 New value for member m100
         */
        inline void m100(int32_t _m100)
        {
            m_m100 = _m100;
        }

        /*!
         * @brief This function returns the value of member m100
         * @return Value of member m100
         */
        inline int32_t m100() const
        {
            return m_m100;
        }

        /*!
         * @brief This function returns a reference to member m100
         * @return Reference to member m100
         */
        inline int32_t& m100()
        {
            return m_m100;
        }
        
        /*!
         * @brief This function calculates the space needed to serialize a type performance::Performance.
         *        For all types with a variable size (strings, sequences) and without a maximum limit, this function uses
         *        255 as maximum limit.
         */
         inline
         size_t getMaxSerializedSize() { return 400;}
         
         /*!
         * @brief This function calculates the space needed to serialize a type performance::Performance without alignment.
         *        For all types with a variable size (strings, sequences) and without a maximum limit, this function uses
         *        255 as maximum limit.
         */
         inline
         size_t getMaxSerializedSizeWithoutAlign(){ return 400;}
        
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
        int32_t m_m11;
        int32_t m_m12;
        int32_t m_m13;
        int32_t m_m14;
        int32_t m_m15;
        int32_t m_m16;
        int32_t m_m17;
        int32_t m_m18;
        int32_t m_m19;
        int32_t m_m20;
        int32_t m_m21;
        int32_t m_m22;
        int32_t m_m23;
        int32_t m_m24;
        int32_t m_m25;
        int32_t m_m26;
        int32_t m_m27;
        int32_t m_m28;
        int32_t m_m29;
        int32_t m_m30;
        int32_t m_m31;
        int32_t m_m32;
        int32_t m_m33;
        int32_t m_m34;
        int32_t m_m35;
        int32_t m_m36;
        int32_t m_m37;
        int32_t m_m38;
        int32_t m_m39;
        int32_t m_m40;
        int32_t m_m41;
        int32_t m_m42;
        int32_t m_m43;
        int32_t m_m44;
        int32_t m_m45;
        int32_t m_m46;
        int32_t m_m47;
        int32_t m_m48;
        int32_t m_m49;
        int32_t m_m50;
        int32_t m_m51;
        int32_t m_m52;
        int32_t m_m53;
        int32_t m_m54;
        int32_t m_m55;
        int32_t m_m56;
        int32_t m_m57;
        int32_t m_m58;
        int32_t m_m59;
        int32_t m_m60;
        int32_t m_m61;
        int32_t m_m62;
        int32_t m_m63;
        int32_t m_m64;
        int32_t m_m65;
        int32_t m_m66;
        int32_t m_m67;
        int32_t m_m68;
        int32_t m_m69;
        int32_t m_m70;
        int32_t m_m71;
        int32_t m_m72;
        int32_t m_m73;
        int32_t m_m74;
        int32_t m_m75;
        int32_t m_m76;
        int32_t m_m77;
        int32_t m_m78;
        int32_t m_m79;
        int32_t m_m80;
        int32_t m_m81;
        int32_t m_m82;
        int32_t m_m83;
        int32_t m_m84;
        int32_t m_m85;
        int32_t m_m86;
        int32_t m_m87;
        int32_t m_m88;
        int32_t m_m89;
        int32_t m_m90;
        int32_t m_m91;
        int32_t m_m92;
        int32_t m_m93;
        int32_t m_m94;
        int32_t m_m95;
        int32_t m_m96;
        int32_t m_m97;
        int32_t m_m98;
        int32_t m_m99;
        int32_t m_m100;
    };
}

#endif // _Performance_100_H_