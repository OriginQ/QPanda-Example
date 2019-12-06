#include "QPanda.h"
USING_QPANDA

int main(void)
{
	auto qvm = initQuantumMachine(GPU);
	auto qubits = qvm->allocateQubits(2);

	QProg prog;
	prog << H(qubits[0])
		<< CNOT(qubits[0], qubits[1]);

	std::cout << "probRunDict: " << std::endl;
	auto result1 = probRunDict(prog, qubits);
	for (auto &val : result1)
	{
		std::cout << val.first << ", " << val.second << std::endl;
	}

	std::cout << "probRunTupleList: " << std::endl;
	auto result2 = probRunTupleList(prog, qubits);
	for (auto &val : result2)
	{
		std::cout << val.first << ", " << val.second << std::endl;
	}

	std::cout << "probRunList: " << std::endl;
	auto result3 = probRunList(prog, qubits);
	for (auto &val : result3)
	{
		std::cout << val << std::endl;
	}

	destroyQuantumMachine(qvm);
	return 0;
}