#include "ResearchDoc.h"



ResearchDoctor::ResearchDoctor(const char* name, const char* expertise) : Doctor(name, expertise), Researcher(name), StaffMember(name)
{
}


ResearchDoctor::~ResearchDoctor()
{
}
