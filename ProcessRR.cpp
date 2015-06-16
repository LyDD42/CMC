#include "ProcessRR.h"

std::ostream& operator<<(std::ostream& o, const ProcessRR& p)
{
	ProcessRR::cst_iter i;
	for (i = p.process1.begin(); i != p.process1.end(); ++i)
		o << (*i).first << "\t" << (*i).second << std::endl;
	for (i = p.process2.begin(); i != p.process2.end(); ++i)
		o << (*i).first << "\t" << (*i).second << std::endl;
	for (i = p.process3.begin(); i != p.process3.end(); ++i)
		o << (*i).first << "\t" << (*i).second << std::endl;
	return o;
}
