#include "QPanda.h"
USING_QPANDA

int main(void)
{
	init();
	auto qvec = qAllocMany(4);
	auto cvec = cAllocMany(4);

	QProg prog;
	prog << H(qvec[0]) << X(qvec[1])
		<< iSWAP(qvec[0], qvec[1])
		<< CNOT(qvec[1], qvec[2])
		<< H(qvec[3]) << MeasureAll(qvec, cvec);

	auto result = runWithConfiguration(prog, cvec, 1000);
	for (auto &val : result)
	{
		std::cout << val.first << ", " << val.second << std::endl;
	}

	finalize();
	return 0;
}