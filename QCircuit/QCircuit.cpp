#include "Core/QPanda.h"
USING_QPANDA

int main(void)
{
	init();
	auto qvec = qAllocMany(4);
	auto cbits = cAllocMany(4);
	auto circuit = createEmptyCircuit();

	circuit << H(qvec[0]) << CNOT(qvec[0], qvec[1])
		<< CNOT(qvec[1], qvec[2]) << CNOT(qvec[2], qvec[3]);
	circuit.setDagger(true);
	auto prog = createEmptyQProg();
	prog << H(qvec[3]) << circuit << Measure(qvec[0], cbits[0]);

	auto result = runWithConfiguration(prog, cbits, 1000);
	for (auto &val : result)
	{
		std::cout << val.first << ", " << val.second << std::endl;
	}

	finalize();
	return 0;
}