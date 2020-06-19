#include "QPanda.h"
USING_QPANDA

int main(void)
{
	init();
	QProg prog;
	auto qvec = qAllocMany(3);
	auto cvec = cAllocMany(3);
	cvec[0].set_val(0);

	QProg prog_in;
	prog_in << cvec[0] << H(qvec[cvec[0]]) << (cvec[0] = cvec[0] + 1);
	auto qwhile = createWhileProg(cvec[0] < 3, prog_in);
	prog << qwhile;
	auto result = probRunTupleList(prog, qvec);

	for (auto & val : result)
	{
		std::cout << val.first << ", " << val.second << std::endl;
	}

	finalize();
	return 0;
}