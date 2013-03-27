#ifndef _PerformanceCDR_H_
#define _PerformanceCDR_H_

#include "Performance.h"
#include "CDR.h"

class PerformanceCDR : public eProsima::CDR
{ 
public:
    PerformanceCDR(eProsima::CDRBuffer &cdrBuffer);
    
    /*!
     * @brief This function serialize type performance::mfloats.
     */
    inline bool operator<<(const performance::mfloats &x){return serialize(x);}

    /*!
     * @brief This function serialize type performance::mfloats.
     */
    bool serialize(const performance::mfloats &x);

    /*!
     * @brief This function deserialize type performance::mfloats.
     */
    inline bool operator>>(performance::mfloats &x){return deserialize(x);}

    /*!
     * @brief This function deserialize type performance::mfloats.
     */
    bool deserialize(performance::mfloats &x);
    /*!
     * @brief This function serialize type performance::mdoubles.
     */
    inline bool operator<<(const performance::mdoubles &x){return serialize(x);}

    /*!
     * @brief This function serialize type performance::mdoubles.
     */
    bool serialize(const performance::mdoubles &x);

    /*!
     * @brief This function deserialize type performance::mdoubles.
     */
    inline bool operator>>(performance::mdoubles &x){return deserialize(x);}

    /*!
     * @brief This function deserialize type performance::mdoubles.
     */
    bool deserialize(performance::mdoubles &x);
    /*!
     * @brief This function serialize type performance::msfixed32s.
     */
    inline bool operator<<(const performance::msfixed32s &x){return serialize(x);}

    /*!
     * @brief This function serialize type performance::msfixed32s.
     */
    bool serialize(const performance::msfixed32s &x);

    /*!
     * @brief This function deserialize type performance::msfixed32s.
     */
    inline bool operator>>(performance::msfixed32s &x){return deserialize(x);}

    /*!
     * @brief This function deserialize type performance::msfixed32s.
     */
    bool deserialize(performance::msfixed32s &x);
    /*!
     * @brief This function serialize type performance::msfixed64s.
     */
    inline bool operator<<(const performance::msfixed64s &x){return serialize(x);}

    /*!
     * @brief This function serialize type performance::msfixed64s.
     */
    bool serialize(const performance::msfixed64s &x);

    /*!
     * @brief This function deserialize type performance::msfixed64s.
     */
    inline bool operator>>(performance::msfixed64s &x){return deserialize(x);}

    /*!
     * @brief This function deserialize type performance::msfixed64s.
     */
    bool deserialize(performance::msfixed64s &x);
    /*!
     * @brief This function serialize type performance::mfixed32s.
     */
    inline bool operator<<(const performance::mfixed32s &x){return serialize(x);}

    /*!
     * @brief This function serialize type performance::mfixed32s.
     */
    bool serialize(const performance::mfixed32s &x);

    /*!
     * @brief This function deserialize type performance::mfixed32s.
     */
    inline bool operator>>(performance::mfixed32s &x){return deserialize(x);}

    /*!
     * @brief This function deserialize type performance::mfixed32s.
     */
    bool deserialize(performance::mfixed32s &x);
    /*!
     * @brief This function serialize type performance::mfixed64s.
     */
    inline bool operator<<(const performance::mfixed64s &x){return serialize(x);}

    /*!
     * @brief This function serialize type performance::mfixed64s.
     */
    bool serialize(const performance::mfixed64s &x);

    /*!
     * @brief This function deserialize type performance::mfixed64s.
     */
    inline bool operator>>(performance::mfixed64s &x){return deserialize(x);}

    /*!
     * @brief This function deserialize type performance::mfixed64s.
     */
    bool deserialize(performance::mfixed64s &x);
    /*!
     * @brief This function serialize type performance::mstrings.
     */
    inline bool operator<<(const performance::mstrings &x){return serialize(x);}

    /*!
     * @brief This function serialize type performance::mstrings.
     */
    bool serialize(const performance::mstrings &x);

    /*!
     * @brief This function deserialize type performance::mstrings.
     */
    inline bool operator>>(performance::mstrings &x){return deserialize(x);}

    /*!
     * @brief This function deserialize type performance::mstrings.
     */
    bool deserialize(performance::mstrings &x);
    /*!
     * @brief This function serialize type performance::Performance.
     */
    inline bool operator<<(const performance::Performance &x){return serialize(x);}

    /*!
     * @brief This function serialize type performance::Performance.
     */
    bool serialize(const performance::Performance &x);

    /*!
     * @brief This function deserialize type performance::Performance.
     */
    inline bool operator>>(performance::Performance &x){return deserialize(x);}

    /*!
     * @brief This function deserialize type performance::Performance.
     */
    bool deserialize(performance::Performance &x);
};

#endif // _PerformanceCDR_H_