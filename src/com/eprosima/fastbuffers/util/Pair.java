/*************************************************************************
 * Copyright (c) 2013 eProsima. All rights reserved.
 *
 * This copy of FastBuffers is licensed to you under the terms described in the
 * FAST_BUFFERS_LICENSE file included in this distribution.
 *
 *************************************************************************/

package com.eprosima.fastbuffers.util;

public class Pair<F, S>
{
    public Pair(F first, S second)
    {
        m_first = first;
        m_second = second;
    }
    
    public F first()
    {
        return m_first;
    }
    
    public S second()
    {
        return m_second;
    }
    
    private F m_first = null;
    
    private S m_second = null;
}
