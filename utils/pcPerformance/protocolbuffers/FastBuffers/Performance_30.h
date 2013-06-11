#ifndef _Performance_30_H_
#define _Performance_30_H_

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
         * @brief This function calculates the space needed to serialize a type performance::Performance.
         *        For all types with a variable size (strings, sequences) and without a maximum limit, this function uses
         *        255 as maximum limit.
         */
         inline
         size_t getMaxSerializedSize() { return 120;}
         
         /*!
         * @brief This function calculates the space needed to serialize a type performance::Performance without alignment.
         *        For all types with a variable size (strings, sequences) and without a maximum limit, this function uses
         *        255 as maximum limit.
         */
         inline
         size_t getMaxSerializedSizeWithoutAlign(){ return 120;}
        
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
    };
}

#endif // _Performance_30_H_