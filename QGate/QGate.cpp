#include "Core/QPanda.h"
USING_QPANDA

int main(void)
{
	init(QMachineType::CPU);
	auto q = qAllocMany(3);
	QVec qubits = { q[0],q[1] };

	auto prog = createEmptyQProg();
	prog << H(q[0])
		<< H(q[1])
		<< H(q[0]).dagger()
		<< X(q[2]).control(qubits);
	auto result = probRunTupleList(prog, q);
	for (auto & aiter : result)
	{
		std::cout << aiter.first << " : " << aiter.second << std::endl;
	}

	finalize();

	return 0;
}