#ifndef __RESEARCH_DOC_H
#define __RESEARCH_DOC_H

#include "doctor.h"
#include "researcher.h"

class ResearchDoctor : public Doctor, public Researcher
{
public:
	ResearchDoctor(const char* name, const char* expertise);
	~ResearchDoctor();

};

#endif;

