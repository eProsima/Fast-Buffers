/*************************************************************************
 * Copyright (c) 2013 eProsima. All rights reserved.
 *
 * This copy of FastBuffers is licensed to you under the terms described in the
 * FAST_BUFFERS_LICENSE file included in this distribution.
 *
 *************************************************************************/

package com.eprosima.fastbuffers.exceptions;

public class ParseException extends RuntimeException
{
	public ParseException()
    {
        super();
    }
    
    public ParseException(String file, int line, String message)
    {
        super("In file " + file + " at line " + line + ": " + message);
    }
}
