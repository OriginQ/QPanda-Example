#include "QPanda.h"
USING_QPANDA

int main(void)
{
	init();
	QProg prog;

	auto qvec = qAllocMany(3);
	auto cvec = cAllocMany(3);
	cvec[1].set_val(0);
	cvec[0].set_val(0);

	QProg branch_true;
	QProg branch_false;
	branch_true << (cvec[1] = cvec[1] + 1) << H(qvec[cvec[0]]) << (cvec[0] = cvec[0] + 1);
	branch_false << H(qvec[0]) << CNOT(qvec[0], qvec[1]) << CNOT(qvec[1], qvec[2]);

	auto qif = createIfProg(cvec[1] > 5, branch_true, branch_false);
	prog << qif;
	auto result = probRunTupleList(prog, qvec);

	for (auto & val : result)
	{
		std::cout << val.first << ", " << val.second << std::endl;
	}

	finalize();
	return 0;
}