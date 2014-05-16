package com.eprosima.fastbuffers.solution;

import java.util.HashSet;

import com.eprosima.solution.GUIDGenerator;

public class Project extends com.eprosima.solution.Project
{
	public Project(String name, String file, HashSet dependencies)
	{
        super(name, file, dependencies);
	}
	
	/*!
	 * @brief Used in string templates.
	 */
	public String getExampleGuid()
	{
		return GUIDGenerator.genGUID(getFile() + "Example");
	}
}
