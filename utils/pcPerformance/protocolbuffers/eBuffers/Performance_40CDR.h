#ifndef _Performance_40CDR_H_
#define _Performance_40CDR_H_

#include "Performance_40.h"
#include "CDR.h"

class Performance_40CDR : public eProsima::CDR
{ 
public:
    Performance_40CDR(eProsima::CDRBuffer &cdrBuffer);
    
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

#endif // _Performance_40CDR_H_