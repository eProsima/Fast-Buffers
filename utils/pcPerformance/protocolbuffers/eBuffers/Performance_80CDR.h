#ifndef _Performance_80CDR_H_
#define _Performance_80CDR_H_

#include "Performance_80.h"
#include "CDR.h"

class Performance_80CDR : public eProsima::CDR
{ 
public:
    Performance_80CDR(eProsima::CDRBuffer &cdrBuffer);
    
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

#endif // _Performance_80CDR_H_