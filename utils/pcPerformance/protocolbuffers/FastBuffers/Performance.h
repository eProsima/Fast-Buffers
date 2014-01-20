#ifndef _Performance_H_
#define _Performance_H_

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
     * @brief This class represents the structure mfloats defined by the user in the IDL file.
     */
    class user_cpp_DllExport mfloats
    {
    public:

        /*!
         * @brief Default constructor.
         */
        mfloats();
        
        /*!
         * @brief Default destructor.
         */
        ~mfloats();
        
        /*!
         * @brief Copy constructor.
         * @param x Reference to the object performance::mfloats that will be copied.
         */
        mfloats(const mfloats &x);
        
        /*!
         * @brief Move constructor.
         * @param x Reference to the object performance::mfloats that will be copied.
         */
        mfloats(mfloats &&x);
        
        /*!
         * @brief Copy assignment.
         * @param x Reference to the object performance::mfloats that will be copied.
         */
        mfloats& operator=(const mfloats &x);
        
        /*!
         * @brief Move assignment.
         * @param x Reference to the object performance::mfloats that will be copied.
         */
        mfloats& operator=(mfloats &&x);
        
        /*!
         * @brief This function sets a value in member m1
         * @param _m1 New value for member m1
         */
        inline void m1(float _m1)
        {
            m_m1 = _m1;
        }

        /*!
         * @brief This function returns the value of member m1
         * @return Value of member m1
         */
        inline float m1() const
        {
            return m_m1;
        }

        /*!
         * @brief This function returns a reference to member m1
         * @return Reference to member m1
         */
        inline float& m1()
        {
            return m_m1;
        }
        /*!
         * @brief This function sets a value in member m2
         * @param _m2 New value for member m2
         */
        inline void m2(float _m2)
        {
            m_m2 = _m2;
        }

        /*!
         * @brief This function returns the value of member m2
         * @return Value of member m2
         */
        inline float m2() const
        {
            return m_m2;
        }

        /*!
         * @brief This function returns a reference to member m2
         * @return Reference to member m2
         */
        inline float& m2()
        {
            return m_m2;
        }
        /*!
         * @brief This function sets a value in member m3
         * @param _m3 New value for member m3
         */
        inline void m3(float _m3)
        {
            m_m3 = _m3;
        }

        /*!
         * @brief This function returns the value of member m3
         * @return Value of member m3
         */
        inline float m3() const
        {
            return m_m3;
        }

        /*!
         * @brief This function returns a reference to member m3
         * @return Reference to member m3
         */
        inline float& m3()
        {
            return m_m3;
        }
        /*!
         * @brief This function sets a value in member m4
         * @param _m4 New value for member m4
         */
        inline void m4(float _m4)
        {
            m_m4 = _m4;
        }

        /*!
         * @brief This function returns the value of member m4
         * @return Value of member m4
         */
        inline float m4() const
        {
            return m_m4;
        }

        /*!
         * @brief This function returns a reference to member m4
         * @return Reference to member m4
         */
        inline float& m4()
        {
            return m_m4;
        }
        /*!
         * @brief This function sets a value in member m5
         * @param _m5 New value for member m5
         */
        inline void m5(float _m5)
        {
            m_m5 = _m5;
        }

        /*!
         * @brief This function returns the value of member m5
         * @return Value of member m5
         */
        inline float m5() const
        {
            return m_m5;
        }

        /*!
         * @brief This function returns a reference to member m5
         * @return Reference to member m5
         */
        inline float& m5()
        {
            return m_m5;
        }
        /*!
         * @brief This function sets a value in member m6
         * @param _m6 New value for member m6
         */
        inline void m6(float _m6)
        {
            m_m6 = _m6;
        }

        /*!
         * @brief This function returns the value of member m6
         * @return Value of member m6
         */
        inline float m6() const
        {
            return m_m6;
        }

        /*!
         * @brief This function returns a reference to member m6
         * @return Reference to member m6
         */
        inline float& m6()
        {
            return m_m6;
        }
        /*!
         * @brief This function sets a value in member m7
         * @param _m7 New value for member m7
         */
        inline void m7(float _m7)
        {
            m_m7 = _m7;
        }

        /*!
         * @brief This function returns the value of member m7
         * @return Value of member m7
         */
        inline float m7() const
        {
            return m_m7;
        }

        /*!
         * @brief This function returns a reference to member m7
         * @return Reference to member m7
         */
        inline float& m7()
        {
            return m_m7;
        }
        /*!
         * @brief This function sets a value in member m8
         * @param _m8 New value for member m8
         */
        inline void m8(float _m8)
        {
            m_m8 = _m8;
        }

        /*!
         * @brief This function returns the value of member m8
         * @return Value of member m8
         */
        inline float m8() const
        {
            return m_m8;
        }

        /*!
         * @brief This function returns a reference to member m8
         * @return Reference to member m8
         */
        inline float& m8()
        {
            return m_m8;
        }
        /*!
         * @brief This function sets a value in member m9
         * @param _m9 New value for member m9
         */
        inline void m9(float _m9)
        {
            m_m9 = _m9;
        }

        /*!
         * @brief This function returns the value of member m9
         * @return Value of member m9
         */
        inline float m9() const
        {
            return m_m9;
        }

        /*!
         * @brief This function returns a reference to member m9
         * @return Reference to member m9
         */
        inline float& m9()
        {
            return m_m9;
        }
        
        /*!
         * @brief This function calculates the space needed to serialize a type performance::mfloats.
         *        For all types with a variable size (strings, sequences) and without a maximum limit, this function uses
         *        255 as maximum limit.
         */
         inline
         size_t getMaxSerializedSize() { return 36;}
         
         /*!
         * @brief This function calculates the space needed to serialize a type performance::mfloats without alignment.
         *        For all types with a variable size (strings, sequences) and without a maximum limit, this function uses
         *        255 as maximum limit.
         */
         inline
         size_t getMaxSerializedSizeWithoutAlign(){ return 36;}
        
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
    /*!
     * @brief This class represents the structure mdoubles defined by the user in the IDL file.
     */
    class user_cpp_DllExport mdoubles
    {
    public:

        /*!
         * @brief Default constructor.
         */
        mdoubles();
        
        /*!
         * @brief Default destructor.
         */
        ~mdoubles();
        
        /*!
         * @brief Copy constructor.
         * @param x Reference to the object performance::mdoubles that will be copied.
         */
        mdoubles(const mdoubles &x);
        
        /*!
         * @brief Move constructor.
         * @param x Reference to the object performance::mdoubles that will be copied.
         */
        mdoubles(mdoubles &&x);
        
        /*!
         * @brief Copy assignment.
         * @param x Reference to the object performance::mdoubles that will be copied.
         */
        mdoubles& operator=(const mdoubles &x);
        
        /*!
         * @brief Move assignment.
         * @param x Reference to the object performance::mdoubles that will be copied.
         */
        mdoubles& operator=(mdoubles &&x);
        
        /*!
         * @brief This function sets a value in member m1
         * @param _m1 New value for member m1
         */
        inline void m1(double _m1)
        {
            m_m1 = _m1;
        }

        /*!
         * @brief This function returns the value of member m1
         * @return Value of member m1
         */
        inline double m1() const
        {
            return m_m1;
        }

        /*!
         * @brief This function returns a reference to member m1
         * @return Reference to member m1
         */
        inline double& m1()
        {
            return m_m1;
        }
        /*!
         * @brief This function sets a value in member m2
         * @param _m2 New value for member m2
         */
        inline void m2(double _m2)
        {
            m_m2 = _m2;
        }

        /*!
         * @brief This function returns the value of member m2
         * @return Value of member m2
         */
        inline double m2() const
        {
            return m_m2;
        }

        /*!
         * @brief This function returns a reference to member m2
         * @return Reference to member m2
         */
        inline double& m2()
        {
            return m_m2;
        }
        /*!
         * @brief This function sets a value in member m3
         * @param _m3 New value for member m3
         */
        inline void m3(double _m3)
        {
            m_m3 = _m3;
        }

        /*!
         * @brief This function returns the value of member m3
         * @return Value of member m3
         */
        inline double m3() const
        {
            return m_m3;
        }

        /*!
         * @brief This function returns a reference to member m3
         * @return Reference to member m3
         */
        inline double& m3()
        {
            return m_m3;
        }
        /*!
         * @brief This function sets a value in member m4
         * @param _m4 New value for member m4
         */
        inline void m4(double _m4)
        {
            m_m4 = _m4;
        }

        /*!
         * @brief This function returns the value of member m4
         * @return Value of member m4
         */
        inline double m4() const
        {
            return m_m4;
        }

        /*!
         * @brief This function returns a reference to member m4
         * @return Reference to member m4
         */
        inline double& m4()
        {
            return m_m4;
        }
        /*!
         * @brief This function sets a value in member m5
         * @param _m5 New value for member m5
         */
        inline void m5(double _m5)
        {
            m_m5 = _m5;
        }

        /*!
         * @brief This function returns the value of member m5
         * @return Value of member m5
         */
        inline double m5() const
        {
            return m_m5;
        }

        /*!
         * @brief This function returns a reference to member m5
         * @return Reference to member m5
         */
        inline double& m5()
        {
            return m_m5;
        }
        /*!
         * @brief This function sets a value in member m6
         * @param _m6 New value for member m6
         */
        inline void m6(double _m6)
        {
            m_m6 = _m6;
        }

        /*!
         * @brief This function returns the value of member m6
         * @return Value of member m6
         */
        inline double m6() const
        {
            return m_m6;
        }

        /*!
         * @brief This function returns a reference to member m6
         * @return Reference to member m6
         */
        inline double& m6()
        {
            return m_m6;
        }
        /*!
         * @brief This function sets a value in member m7
         * @param _m7 New value for member m7
         */
        inline void m7(double _m7)
        {
            m_m7 = _m7;
        }

        /*!
         * @brief This function returns the value of member m7
         * @return Value of member m7
         */
        inline double m7() const
        {
            return m_m7;
        }

        /*!
         * @brief This function returns a reference to member m7
         * @return Reference to member m7
         */
        inline double& m7()
        {
            return m_m7;
        }
        /*!
         * @brief This function sets a value in member m8
         * @param _m8 New value for member m8
         */
        inline void m8(double _m8)
        {
            m_m8 = _m8;
        }

        /*!
         * @brief This function returns the value of member m8
         * @return Value of member m8
         */
        inline double m8() const
        {
            return m_m8;
        }

        /*!
         * @brief This function returns a reference to member m8
         * @return Reference to member m8
         */
        inline double& m8()
        {
            return m_m8;
        }
        /*!
         * @brief This function sets a value in member m9
         * @param _m9 New value for member m9
         */
        inline void m9(double _m9)
        {
            m_m9 = _m9;
        }

        /*!
         * @brief This function returns the value of member m9
         * @return Value of member m9
         */
        inline double m9() const
        {
            return m_m9;
        }

        /*!
         * @brief This function returns a reference to member m9
         * @return Reference to member m9
         */
        inline double& m9()
        {
            return m_m9;
        }
        
        /*!
         * @brief This function calculates the space needed to serialize a type performance::mdoubles.
         *        For all types with a variable size (strings, sequences) and without a maximum limit, this function uses
         *        255 as maximum limit.
         */
         inline
         size_t getMaxSerializedSize() { return 72;}
         
         /*!
         * @brief This function calculates the space needed to serialize a type performance::mdoubles without alignment.
         *        For all types with a variable size (strings, sequences) and without a maximum limit, this function uses
         *        255 as maximum limit.
         */
         inline
         size_t getMaxSerializedSizeWithoutAlign(){ return 72;}
        
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
    /*!
     * @brief This class represents the structure msfixed32s defined by the user in the IDL file.
     */
    class user_cpp_DllExport msfixed32s
    {
    public:

        /*!
         * @brief Default constructor.
         */
        msfixed32s();
        
        /*!
         * @brief Default destructor.
         */
        ~msfixed32s();
        
        /*!
         * @brief Copy constructor.
         * @param x Reference to the object performance::msfixed32s that will be copied.
         */
        msfixed32s(const msfixed32s &x);
        
        /*!
         * @brief Move constructor.
         * @param x Reference to the object performance::msfixed32s that will be copied.
         */
        msfixed32s(msfixed32s &&x);
        
        /*!
         * @brief Copy assignment.
         * @param x Reference to the object performance::msfixed32s that will be copied.
         */
        msfixed32s& operator=(const msfixed32s &x);
        
        /*!
         * @brief Move assignment.
         * @param x Reference to the object performance::msfixed32s that will be copied.
         */
        msfixed32s& operator=(msfixed32s &&x);
        
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
         * @brief This function calculates the space needed to serialize a type performance::msfixed32s.
         *        For all types with a variable size (strings, sequences) and without a maximum limit, this function uses
         *        255 as maximum limit.
         */
         inline
         size_t getMaxSerializedSize() { return 36;}
         
         /*!
         * @brief This function calculates the space needed to serialize a type performance::msfixed32s without alignment.
         *        For all types with a variable size (strings, sequences) and without a maximum limit, this function uses
         *        255 as maximum limit.
         */
         inline
         size_t getMaxSerializedSizeWithoutAlign(){ return 36;}
        
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
    /*!
     * @brief This class represents the structure msfixed64s defined by the user in the IDL file.
     */
    class user_cpp_DllExport msfixed64s
    {
    public:

        /*!
         * @brief Default constructor.
         */
        msfixed64s();
        
        /*!
         * @brief Default destructor.
         */
        ~msfixed64s();
        
        /*!
         * @brief Copy constructor.
         * @param x Reference to the object performance::msfixed64s that will be copied.
         */
        msfixed64s(const msfixed64s &x);
        
        /*!
         * @brief Move constructor.
         * @param x Reference to the object performance::msfixed64s that will be copied.
         */
        msfixed64s(msfixed64s &&x);
        
        /*!
         * @brief Copy assignment.
         * @param x Reference to the object performance::msfixed64s that will be copied.
         */
        msfixed64s& operator=(const msfixed64s &x);
        
        /*!
         * @brief Move assignment.
         * @param x Reference to the object performance::msfixed64s that will be copied.
         */
        msfixed64s& operator=(msfixed64s &&x);
        
        /*!
         * @brief This function sets a value in member m1
         * @param _m1 New value for member m1
         */
        inline void m1(int64_t _m1)
        {
            m_m1 = _m1;
        }

        /*!
         * @brief This function returns the value of member m1
         * @return Value of member m1
         */
        inline int64_t m1() const
        {
            return m_m1;
        }

        /*!
         * @brief This function returns a reference to member m1
         * @return Reference to member m1
         */
        inline int64_t& m1()
        {
            return m_m1;
        }
        /*!
         * @brief This function sets a value in member m2
         * @param _m2 New value for member m2
         */
        inline void m2(int64_t _m2)
        {
            m_m2 = _m2;
        }

        /*!
         * @brief This function returns the value of member m2
         * @return Value of member m2
         */
        inline int64_t m2() const
        {
            return m_m2;
        }

        /*!
         * @brief This function returns a reference to member m2
         * @return Reference to member m2
         */
        inline int64_t& m2()
        {
            return m_m2;
        }
        /*!
         * @brief This function sets a value in member m3
         * @param _m3 New value for member m3
         */
        inline void m3(int64_t _m3)
        {
            m_m3 = _m3;
        }

        /*!
         * @brief This function returns the value of member m3
         * @return Value of member m3
         */
        inline int64_t m3() const
        {
            return m_m3;
        }

        /*!
         * @brief This function returns a reference to member m3
         * @return Reference to member m3
         */
        inline int64_t& m3()
        {
            return m_m3;
        }
        /*!
         * @brief This function sets a value in member m4
         * @param _m4 New value for member m4
         */
        inline void m4(int64_t _m4)
        {
            m_m4 = _m4;
        }

        /*!
         * @brief This function returns the value of member m4
         * @return Value of member m4
         */
        inline int64_t m4() const
        {
            return m_m4;
        }

        /*!
         * @brief This function returns a reference to member m4
         * @return Reference to member m4
         */
        inline int64_t& m4()
        {
            return m_m4;
        }
        /*!
         * @brief This function sets a value in member m5
         * @param _m5 New value for member m5
         */
        inline void m5(int64_t _m5)
        {
            m_m5 = _m5;
        }

        /*!
         * @brief This function returns the value of member m5
         * @return Value of member m5
         */
        inline int64_t m5() const
        {
            return m_m5;
        }

        /*!
         * @brief This function returns a reference to member m5
         * @return Reference to member m5
         */
        inline int64_t& m5()
        {
            return m_m5;
        }
        /*!
         * @brief This function sets a value in member m6
         * @param _m6 New value for member m6
         */
        inline void m6(int64_t _m6)
        {
            m_m6 = _m6;
        }

        /*!
         * @brief This function returns the value of member m6
         * @return Value of member m6
         */
        inline int64_t m6() const
        {
            return m_m6;
        }

        /*!
         * @brief This function returns a reference to member m6
         * @return Reference to member m6
         */
        inline int64_t& m6()
        {
            return m_m6;
        }
        /*!
         * @brief This function sets a value in member m7
         * @param _m7 New value for member m7
         */
        inline void m7(int64_t _m7)
        {
            m_m7 = _m7;
        }

        /*!
         * @brief This function returns the value of member m7
         * @return Value of member m7
         */
        inline int64_t m7() const
        {
            return m_m7;
        }

        /*!
         * @brief This function returns a reference to member m7
         * @return Reference to member m7
         */
        inline int64_t& m7()
        {
            return m_m7;
        }
        /*!
         * @brief This function sets a value in member m8
         * @param _m8 New value for member m8
         */
        inline void m8(int64_t _m8)
        {
            m_m8 = _m8;
        }

        /*!
         * @brief This function returns the value of member m8
         * @return Value of member m8
         */
        inline int64_t m8() const
        {
            return m_m8;
        }

        /*!
         * @brief This function returns a reference to member m8
         * @return Reference to member m8
         */
        inline int64_t& m8()
        {
            return m_m8;
        }
        /*!
         * @brief This function sets a value in member m9
         * @param _m9 New value for member m9
         */
        inline void m9(int64_t _m9)
        {
            m_m9 = _m9;
        }

        /*!
         * @brief This function returns the value of member m9
         * @return Value of member m9
         */
        inline int64_t m9() const
        {
            return m_m9;
        }

        /*!
         * @brief This function returns a reference to member m9
         * @return Reference to member m9
         */
        inline int64_t& m9()
        {
            return m_m9;
        }
        
        /*!
         * @brief This function calculates the space needed to serialize a type performance::msfixed64s.
         *        For all types with a variable size (strings, sequences) and without a maximum limit, this function uses
         *        255 as maximum limit.
         */
         inline
         size_t getMaxSerializedSize() { return 72;}
         
         /*!
         * @brief This function calculates the space needed to serialize a type performance::msfixed64s without alignment.
         *        For all types with a variable size (strings, sequences) and without a maximum limit, this function uses
         *        255 as maximum limit.
         */
         inline
         size_t getMaxSerializedSizeWithoutAlign(){ return 72;}
        
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
    /*!
     * @brief This class represents the structure mfixed32s defined by the user in the IDL file.
     */
    class user_cpp_DllExport mfixed32s
    {
    public:

        /*!
         * @brief Default constructor.
         */
        mfixed32s();
        
        /*!
         * @brief Default destructor.
         */
        ~mfixed32s();
        
        /*!
         * @brief Copy constructor.
         * @param x Reference to the object performance::mfixed32s that will be copied.
         */
        mfixed32s(const mfixed32s &x);
        
        /*!
         * @brief Move constructor.
         * @param x Reference to the object performance::mfixed32s that will be copied.
         */
        mfixed32s(mfixed32s &&x);
        
        /*!
         * @brief Copy assignment.
         * @param x Reference to the object performance::mfixed32s that will be copied.
         */
        mfixed32s& operator=(const mfixed32s &x);
        
        /*!
         * @brief Move assignment.
         * @param x Reference to the object performance::mfixed32s that will be copied.
         */
        mfixed32s& operator=(mfixed32s &&x);
        
        /*!
         * @brief This function sets a value in member m1
         * @param _m1 New value for member m1
         */
        inline void m1(uint32_t _m1)
        {
            m_m1 = _m1;
        }

        /*!
         * @brief This function returns the value of member m1
         * @return Value of member m1
         */
        inline uint32_t m1() const
        {
            return m_m1;
        }

        /*!
         * @brief This function returns a reference to member m1
         * @return Reference to member m1
         */
        inline uint32_t& m1()
        {
            return m_m1;
        }
        /*!
         * @brief This function sets a value in member m2
         * @param _m2 New value for member m2
         */
        inline void m2(uint32_t _m2)
        {
            m_m2 = _m2;
        }

        /*!
         * @brief This function returns the value of member m2
         * @return Value of member m2
         */
        inline uint32_t m2() const
        {
            return m_m2;
        }

        /*!
         * @brief This function returns a reference to member m2
         * @return Reference to member m2
         */
        inline uint32_t& m2()
        {
            return m_m2;
        }
        /*!
         * @brief This function sets a value in member m3
         * @param _m3 New value for member m3
         */
        inline void m3(uint32_t _m3)
        {
            m_m3 = _m3;
        }

        /*!
         * @brief This function returns the value of member m3
         * @return Value of member m3
         */
        inline uint32_t m3() const
        {
            return m_m3;
        }

        /*!
         * @brief This function returns a reference to member m3
         * @return Reference to member m3
         */
        inline uint32_t& m3()
        {
            return m_m3;
        }
        /*!
         * @brief This function sets a value in member m4
         * @param _m4 New value for member m4
         */
        inline void m4(uint32_t _m4)
        {
            m_m4 = _m4;
        }

        /*!
         * @brief This function returns the value of member m4
         * @return Value of member m4
         */
        inline uint32_t m4() const
        {
            return m_m4;
        }

        /*!
         * @brief This function returns a reference to member m4
         * @return Reference to member m4
         */
        inline uint32_t& m4()
        {
            return m_m4;
        }
        /*!
         * @brief This function sets a value in member m5
         * @param _m5 New value for member m5
         */
        inline void m5(uint32_t _m5)
        {
            m_m5 = _m5;
        }

        /*!
         * @brief This function returns the value of member m5
         * @return Value of member m5
         */
        inline uint32_t m5() const
        {
            return m_m5;
        }

        /*!
         * @brief This function returns a reference to member m5
         * @return Reference to member m5
         */
        inline uint32_t& m5()
        {
            return m_m5;
        }
        /*!
         * @brief This function sets a value in member m6
         * @param _m6 New value for member m6
         */
        inline void m6(uint32_t _m6)
        {
            m_m6 = _m6;
        }

        /*!
         * @brief This function returns the value of member m6
         * @return Value of member m6
         */
        inline uint32_t m6() const
        {
            return m_m6;
        }

        /*!
         * @brief This function returns a reference to member m6
         * @return Reference to member m6
         */
        inline uint32_t& m6()
        {
            return m_m6;
        }
        /*!
         * @brief This function sets a value in member m7
         * @param _m7 New value for member m7
         */
        inline void m7(uint32_t _m7)
        {
            m_m7 = _m7;
        }

        /*!
         * @brief This function returns the value of member m7
         * @return Value of member m7
         */
        inline uint32_t m7() const
        {
            return m_m7;
        }

        /*!
         * @brief This function returns a reference to member m7
         * @return Reference to member m7
         */
        inline uint32_t& m7()
        {
            return m_m7;
        }
        /*!
         * @brief This function sets a value in member m8
         * @param _m8 New value for member m8
         */
        inline void m8(uint32_t _m8)
        {
            m_m8 = _m8;
        }

        /*!
         * @brief This function returns the value of member m8
         * @return Value of member m8
         */
        inline uint32_t m8() const
        {
            return m_m8;
        }

        /*!
         * @brief This function returns a reference to member m8
         * @return Reference to member m8
         */
        inline uint32_t& m8()
        {
            return m_m8;
        }
        /*!
         * @brief This function sets a value in member m9
         * @param _m9 New value for member m9
         */
        inline void m9(uint32_t _m9)
        {
            m_m9 = _m9;
        }

        /*!
         * @brief This function returns the value of member m9
         * @return Value of member m9
         */
        inline uint32_t m9() const
        {
            return m_m9;
        }

        /*!
         * @brief This function returns a reference to member m9
         * @return Reference to member m9
         */
        inline uint32_t& m9()
        {
            return m_m9;
        }
        
        /*!
         * @brief This function calculates the space needed to serialize a type performance::mfixed32s.
         *        For all types with a variable size (strings, sequences) and without a maximum limit, this function uses
         *        255 as maximum limit.
         */
         inline
         size_t getMaxSerializedSize() { return 36;}
         
         /*!
         * @brief This function calculates the space needed to serialize a type performance::mfixed32s without alignment.
         *        For all types with a variable size (strings, sequences) and without a maximum limit, this function uses
         *        255 as maximum limit.
         */
         inline
         size_t getMaxSerializedSizeWithoutAlign(){ return 36;}
        
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
    /*!
     * @brief This class represents the structure mfixed64s defined by the user in the IDL file.
     */
    class user_cpp_DllExport mfixed64s
    {
    public:

        /*!
         * @brief Default constructor.
         */
        mfixed64s();
        
        /*!
         * @brief Default destructor.
         */
        ~mfixed64s();
        
        /*!
         * @brief Copy constructor.
         * @param x Reference to the object performance::mfixed64s that will be copied.
         */
        mfixed64s(const mfixed64s &x);
        
        /*!
         * @brief Move constructor.
         * @param x Reference to the object performance::mfixed64s that will be copied.
         */
        mfixed64s(mfixed64s &&x);
        
        /*!
         * @brief Copy assignment.
         * @param x Reference to the object performance::mfixed64s that will be copied.
         */
        mfixed64s& operator=(const mfixed64s &x);
        
        /*!
         * @brief Move assignment.
         * @param x Reference to the object performance::mfixed64s that will be copied.
         */
        mfixed64s& operator=(mfixed64s &&x);
        
        /*!
         * @brief This function sets a value in member m1
         * @param _m1 New value for member m1
         */
        inline void m1(uint64_t _m1)
        {
            m_m1 = _m1;
        }

        /*!
         * @brief This function returns the value of member m1
         * @return Value of member m1
         */
        inline uint64_t m1() const
        {
            return m_m1;
        }

        /*!
         * @brief This function returns a reference to member m1
         * @return Reference to member m1
         */
        inline uint64_t& m1()
        {
            return m_m1;
        }
        /*!
         * @brief This function sets a value in member m2
         * @param _m2 New value for member m2
         */
        inline void m2(uint64_t _m2)
        {
            m_m2 = _m2;
        }

        /*!
         * @brief This function returns the value of member m2
         * @return Value of member m2
         */
        inline uint64_t m2() const
        {
            return m_m2;
        }

        /*!
         * @brief This function returns a reference to member m2
         * @return Reference to member m2
         */
        inline uint64_t& m2()
        {
            return m_m2;
        }
        /*!
         * @brief This function sets a value in member m3
         * @param _m3 New value for member m3
         */
        inline void m3(uint64_t _m3)
        {
            m_m3 = _m3;
        }

        /*!
         * @brief This function returns the value of member m3
         * @return Value of member m3
         */
        inline uint64_t m3() const
        {
            return m_m3;
        }

        /*!
         * @brief This function returns a reference to member m3
         * @return Reference to member m3
         */
        inline uint64_t& m3()
        {
            return m_m3;
        }
        /*!
         * @brief This function sets a value in member m4
         * @param _m4 New value for member m4
         */
        inline void m4(uint64_t _m4)
        {
            m_m4 = _m4;
        }

        /*!
         * @brief This function returns the value of member m4
         * @return Value of member m4
         */
        inline uint64_t m4() const
        {
            return m_m4;
        }

        /*!
         * @brief This function returns a reference to member m4
         * @return Reference to member m4
         */
        inline uint64_t& m4()
        {
            return m_m4;
        }
        /*!
         * @brief This function sets a value in member m5
         * @param _m5 New value for member m5
         */
        inline void m5(uint64_t _m5)
        {
            m_m5 = _m5;
        }

        /*!
         * @brief This function returns the value of member m5
         * @return Value of member m5
         */
        inline uint64_t m5() const
        {
            return m_m5;
        }

        /*!
         * @brief This function returns a reference to member m5
         * @return Reference to member m5
         */
        inline uint64_t& m5()
        {
            return m_m5;
        }
        /*!
         * @brief This function sets a value in member m6
         * @param _m6 New value for member m6
         */
        inline void m6(uint64_t _m6)
        {
            m_m6 = _m6;
        }

        /*!
         * @brief This function returns the value of member m6
         * @return Value of member m6
         */
        inline uint64_t m6() const
        {
            return m_m6;
        }

        /*!
         * @brief This function returns a reference to member m6
         * @return Reference to member m6
         */
        inline uint64_t& m6()
        {
            return m_m6;
        }
        /*!
         * @brief This function sets a value in member m7
         * @param _m7 New value for member m7
         */
        inline void m7(uint64_t _m7)
        {
            m_m7 = _m7;
        }

        /*!
         * @brief This function returns the value of member m7
         * @return Value of member m7
         */
        inline uint64_t m7() const
        {
            return m_m7;
        }

        /*!
         * @brief This function returns a reference to member m7
         * @return Reference to member m7
         */
        inline uint64_t& m7()
        {
            return m_m7;
        }
        /*!
         * @brief This function sets a value in member m8
         * @param _m8 New value for member m8
         */
        inline void m8(uint64_t _m8)
        {
            m_m8 = _m8;
        }

        /*!
         * @brief This function returns the value of member m8
         * @return Value of member m8
         */
        inline uint64_t m8() const
        {
            return m_m8;
        }

        /*!
         * @brief This function returns a reference to member m8
         * @return Reference to member m8
         */
        inline uint64_t& m8()
        {
            return m_m8;
        }
        /*!
         * @brief This function sets a value in member m9
         * @param _m9 New value for member m9
         */
        inline void m9(uint64_t _m9)
        {
            m_m9 = _m9;
        }

        /*!
         * @brief This function returns the value of member m9
         * @return Value of member m9
         */
        inline uint64_t m9() const
        {
            return m_m9;
        }

        /*!
         * @brief This function returns a reference to member m9
         * @return Reference to member m9
         */
        inline uint64_t& m9()
        {
            return m_m9;
        }
        
        /*!
         * @brief This function calculates the space needed to serialize a type performance::mfixed64s.
         *        For all types with a variable size (strings, sequences) and without a maximum limit, this function uses
         *        255 as maximum limit.
         */
         inline
         size_t getMaxSerializedSize() { return 72;}
         
         /*!
         * @brief This function calculates the space needed to serialize a type performance::mfixed64s without alignment.
         *        For all types with a variable size (strings, sequences) and without a maximum limit, this function uses
         *        255 as maximum limit.
         */
         inline
         size_t getMaxSerializedSizeWithoutAlign(){ return 72;}
        
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
    /*!
     * @brief This class represents the structure mstrings defined by the user in the IDL file.
     */
    class user_cpp_DllExport mstrings
    {
    public:

        /*!
         * @brief Default constructor.
         */
        mstrings();
        
        /*!
         * @brief Default destructor.
         */
        ~mstrings();
        
        /*!
         * @brief Copy constructor.
         * @param x Reference to the object performance::mstrings that will be copied.
         */
        mstrings(const mstrings &x);
        
        /*!
         * @brief Move constructor.
         * @param x Reference to the object performance::mstrings that will be copied.
         */
        mstrings(mstrings &&x);
        
        /*!
         * @brief Copy assignment.
         * @param x Reference to the object performance::mstrings that will be copied.
         */
        mstrings& operator=(const mstrings &x);
        
        /*!
         * @brief Move assignment.
         * @param x Reference to the object performance::mstrings that will be copied.
         */
        mstrings& operator=(mstrings &&x);
        
        /*!
         * @brief This function copies the value in member m1
         * @param _m1 New value to be copied in member m1
         */
        inline void m1(const std::string &_m1)
        {
            m_m1 = _m1;
        }

        /*!
         * @brief This function moves the value in member m1
         * @param _m1 New value to be moved in member m1
         */
        inline void m1(std::string &&_m1)
        {
            m_m1 = std::move(_m1);
        }

        /*!
         * @brief This function returns a constant reference to member m1
         * @return Constant reference to member m1
         */
        inline const std::string& m1() const
        {
            return m_m1;
        }

        /*!
         * @brief This function returns a reference to member m1
         * @return Reference to member m1
         */
        inline std::string& m1()
        {
            return m_m1;
        }
        /*!
         * @brief This function copies the value in member m2
         * @param _m2 New value to be copied in member m2
         */
        inline void m2(const std::string &_m2)
        {
            m_m2 = _m2;
        }

        /*!
         * @brief This function moves the value in member m2
         * @param _m2 New value to be moved in member m2
         */
        inline void m2(std::string &&_m2)
        {
            m_m2 = std::move(_m2);
        }

        /*!
         * @brief This function returns a constant reference to member m2
         * @return Constant reference to member m2
         */
        inline const std::string& m2() const
        {
            return m_m2;
        }

        /*!
         * @brief This function returns a reference to member m2
         * @return Reference to member m2
         */
        inline std::string& m2()
        {
            return m_m2;
        }
        /*!
         * @brief This function copies the value in member m3
         * @param _m3 New value to be copied in member m3
         */
        inline void m3(const std::string &_m3)
        {
            m_m3 = _m3;
        }

        /*!
         * @brief This function moves the value in member m3
         * @param _m3 New value to be moved in member m3
         */
        inline void m3(std::string &&_m3)
        {
            m_m3 = std::move(_m3);
        }

        /*!
         * @brief This function returns a constant reference to member m3
         * @return Constant reference to member m3
         */
        inline const std::string& m3() const
        {
            return m_m3;
        }

        /*!
         * @brief This function returns a reference to member m3
         * @return Reference to member m3
         */
        inline std::string& m3()
        {
            return m_m3;
        }
        /*!
         * @brief This function copies the value in member m4
         * @param _m4 New value to be copied in member m4
         */
        inline void m4(const std::string &_m4)
        {
            m_m4 = _m4;
        }

        /*!
         * @brief This function moves the value in member m4
         * @param _m4 New value to be moved in member m4
         */
        inline void m4(std::string &&_m4)
        {
            m_m4 = std::move(_m4);
        }

        /*!
         * @brief This function returns a constant reference to member m4
         * @return Constant reference to member m4
         */
        inline const std::string& m4() const
        {
            return m_m4;
        }

        /*!
         * @brief This function returns a reference to member m4
         * @return Reference to member m4
         */
        inline std::string& m4()
        {
            return m_m4;
        }
        /*!
         * @brief This function copies the value in member m5
         * @param _m5 New value to be copied in member m5
         */
        inline void m5(const std::string &_m5)
        {
            m_m5 = _m5;
        }

        /*!
         * @brief This function moves the value in member m5
         * @param _m5 New value to be moved in member m5
         */
        inline void m5(std::string &&_m5)
        {
            m_m5 = std::move(_m5);
        }

        /*!
         * @brief This function returns a constant reference to member m5
         * @return Constant reference to member m5
         */
        inline const std::string& m5() const
        {
            return m_m5;
        }

        /*!
         * @brief This function returns a reference to member m5
         * @return Reference to member m5
         */
        inline std::string& m5()
        {
            return m_m5;
        }
        /*!
         * @brief This function copies the value in member m6
         * @param _m6 New value to be copied in member m6
         */
        inline void m6(const std::string &_m6)
        {
            m_m6 = _m6;
        }

        /*!
         * @brief This function moves the value in member m6
         * @param _m6 New value to be moved in member m6
         */
        inline void m6(std::string &&_m6)
        {
            m_m6 = std::move(_m6);
        }

        /*!
         * @brief This function returns a constant reference to member m6
         * @return Constant reference to member m6
         */
        inline const std::string& m6() const
        {
            return m_m6;
        }

        /*!
         * @brief This function returns a reference to member m6
         * @return Reference to member m6
         */
        inline std::string& m6()
        {
            return m_m6;
        }
        /*!
         * @brief This function copies the value in member m7
         * @param _m7 New value to be copied in member m7
         */
        inline void m7(const std::string &_m7)
        {
            m_m7 = _m7;
        }

        /*!
         * @brief This function moves the value in member m7
         * @param _m7 New value to be moved in member m7
         */
        inline void m7(std::string &&_m7)
        {
            m_m7 = std::move(_m7);
        }

        /*!
         * @brief This function returns a constant reference to member m7
         * @return Constant reference to member m7
         */
        inline const std::string& m7() const
        {
            return m_m7;
        }

        /*!
         * @brief This function returns a reference to member m7
         * @return Reference to member m7
         */
        inline std::string& m7()
        {
            return m_m7;
        }
        /*!
         * @brief This function copies the value in member m8
         * @param _m8 New value to be copied in member m8
         */
        inline void m8(const std::string &_m8)
        {
            m_m8 = _m8;
        }

        /*!
         * @brief This function moves the value in member m8
         * @param _m8 New value to be moved in member m8
         */
        inline void m8(std::string &&_m8)
        {
            m_m8 = std::move(_m8);
        }

        /*!
         * @brief This function returns a constant reference to member m8
         * @return Constant reference to member m8
         */
        inline const std::string& m8() const
        {
            return m_m8;
        }

        /*!
         * @brief This function returns a reference to member m8
         * @return Reference to member m8
         */
        inline std::string& m8()
        {
            return m_m8;
        }
        /*!
         * @brief This function copies the value in member m9
         * @param _m9 New value to be copied in member m9
         */
        inline void m9(const std::string &_m9)
        {
            m_m9 = _m9;
        }

        /*!
         * @brief This function moves the value in member m9
         * @param _m9 New value to be moved in member m9
         */
        inline void m9(std::string &&_m9)
        {
            m_m9 = std::move(_m9);
        }

        /*!
         * @brief This function returns a constant reference to member m9
         * @return Constant reference to member m9
         */
        inline const std::string& m9() const
        {
            return m_m9;
        }

        /*!
         * @brief This function returns a reference to member m9
         * @return Reference to member m9
         */
        inline std::string& m9()
        {
            return m_m9;
        }
        
        /*!
         * @brief This function calculates the space needed to serialize a type performance::mstrings.
         *        For all types with a variable size (strings, sequences) and without a maximum limit, this function uses
         *        255 as maximum limit.
         */
         inline
         size_t getMaxSerializedSize() { return 2339;}
         
         /*!
         * @brief This function calculates the space needed to serialize a type performance::mstrings without alignment.
         *        For all types with a variable size (strings, sequences) and without a maximum limit, this function uses
         *        255 as maximum limit.
         */
         inline
         size_t getMaxSerializedSizeWithoutAlign(){ return 2331;}
        
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
         * @brief This function copies the value in member mf
         * @param _mf New value to be copied in member mf
         */
        inline void mf(const performance::mfloats &_mf)
        {
            m_mf = _mf;
        }

        /*!
         * @brief This function moves the value in member mf
         * @param _mf New value to be moved in member mf
         */
        inline void mf(performance::mfloats &&_mf)
        {
            m_mf = std::move(_mf);
        }

        /*!
         * @brief This function returns a constant reference to member mf
         * @return Constant reference to member mf
         */
        inline const performance::mfloats& mf() const
        {
            return m_mf;
        }

        /*!
         * @brief This function returns a reference to member mf
         * @return Reference to member mf
         */
        inline performance::mfloats& mf()
        {
            return m_mf;
        }
        /*!
         * @brief This function copies the value in member md
         * @param _md New value to be copied in member md
         */
        inline void md(const performance::mdoubles &_md)
        {
            m_md = _md;
        }

        /*!
         * @brief This function moves the value in member md
         * @param _md New value to be moved in member md
         */
        inline void md(performance::mdoubles &&_md)
        {
            m_md = std::move(_md);
        }

        /*!
         * @brief This function returns a constant reference to member md
         * @return Constant reference to member md
         */
        inline const performance::mdoubles& md() const
        {
            return m_md;
        }

        /*!
         * @brief This function returns a reference to member md
         * @return Reference to member md
         */
        inline performance::mdoubles& md()
        {
            return m_md;
        }
        /*!
         * @brief This function copies the value in member msf3
         * @param _msf3 New value to be copied in member msf3
         */
        inline void msf3(const performance::msfixed32s &_msf3)
        {
            m_msf3 = _msf3;
        }

        /*!
         * @brief This function moves the value in member msf3
         * @param _msf3 New value to be moved in member msf3
         */
        inline void msf3(performance::msfixed32s &&_msf3)
        {
            m_msf3 = std::move(_msf3);
        }

        /*!
         * @brief This function returns a constant reference to member msf3
         * @return Constant reference to member msf3
         */
        inline const performance::msfixed32s& msf3() const
        {
            return m_msf3;
        }

        /*!
         * @brief This function returns a reference to member msf3
         * @return Reference to member msf3
         */
        inline performance::msfixed32s& msf3()
        {
            return m_msf3;
        }
        /*!
         * @brief This function copies the value in member msf6
         * @param _msf6 New value to be copied in member msf6
         */
        inline void msf6(const performance::msfixed64s &_msf6)
        {
            m_msf6 = _msf6;
        }

        /*!
         * @brief This function moves the value in member msf6
         * @param _msf6 New value to be moved in member msf6
         */
        inline void msf6(performance::msfixed64s &&_msf6)
        {
            m_msf6 = std::move(_msf6);
        }

        /*!
         * @brief This function returns a constant reference to member msf6
         * @return Constant reference to member msf6
         */
        inline const performance::msfixed64s& msf6() const
        {
            return m_msf6;
        }

        /*!
         * @brief This function returns a reference to member msf6
         * @return Reference to member msf6
         */
        inline performance::msfixed64s& msf6()
        {
            return m_msf6;
        }
        /*!
         * @brief This function copies the value in member mf3
         * @param _mf3 New value to be copied in member mf3
         */
        inline void mf3(const performance::mfixed32s &_mf3)
        {
            m_mf3 = _mf3;
        }

        /*!
         * @brief This function moves the value in member mf3
         * @param _mf3 New value to be moved in member mf3
         */
        inline void mf3(performance::mfixed32s &&_mf3)
        {
            m_mf3 = std::move(_mf3);
        }

        /*!
         * @brief This function returns a constant reference to member mf3
         * @return Constant reference to member mf3
         */
        inline const performance::mfixed32s& mf3() const
        {
            return m_mf3;
        }

        /*!
         * @brief This function returns a reference to member mf3
         * @return Reference to member mf3
         */
        inline performance::mfixed32s& mf3()
        {
            return m_mf3;
        }
        /*!
         * @brief This function copies the value in member mf6
         * @param _mf6 New value to be copied in member mf6
         */
        inline void mf6(const performance::mfixed64s &_mf6)
        {
            m_mf6 = _mf6;
        }

        /*!
         * @brief This function moves the value in member mf6
         * @param _mf6 New value to be moved in member mf6
         */
        inline void mf6(performance::mfixed64s &&_mf6)
        {
            m_mf6 = std::move(_mf6);
        }

        /*!
         * @brief This function returns a constant reference to member mf6
         * @return Constant reference to member mf6
         */
        inline const performance::mfixed64s& mf6() const
        {
            return m_mf6;
        }

        /*!
         * @brief This function returns a reference to member mf6
         * @return Reference to member mf6
         */
        inline performance::mfixed64s& mf6()
        {
            return m_mf6;
        }
        /*!
         * @brief This function copies the value in member mstr
         * @param _mstr New value to be copied in member mstr
         */
        inline void mstr(const performance::mstrings &_mstr)
        {
            m_mstr = _mstr;
        }

        /*!
         * @brief This function moves the value in member mstr
         * @param _mstr New value to be moved in member mstr
         */
        inline void mstr(performance::mstrings &&_mstr)
        {
            m_mstr = std::move(_mstr);
        }

        /*!
         * @brief This function returns a constant reference to member mstr
         * @return Constant reference to member mstr
         */
        inline const performance::mstrings& mstr() const
        {
            return m_mstr;
        }

        /*!
         * @brief This function returns a reference to member mstr
         * @return Reference to member mstr
         */
        inline performance::mstrings& mstr()
        {
            return m_mstr;
        }
        
        /*!
         * @brief This function calculates the space needed to serialize a type performance::Performance.
         *        For all types with a variable size (strings, sequences) and without a maximum limit, this function uses
         *        255 as maximum limit.
         */
         inline
         size_t getMaxSerializedSize() { return 2675;}
         
         /*!
         * @brief This function calculates the space needed to serialize a type performance::Performance without alignment.
         *        For all types with a variable size (strings, sequences) and without a maximum limit, this function uses
         *        255 as maximum limit.
         */
         inline
         size_t getMaxSerializedSizeWithoutAlign(){ return 2655;}
        
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