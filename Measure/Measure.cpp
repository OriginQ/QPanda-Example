#include <QPanda.h>
USING_QPANDA

int main(void)
{
	auto qvm = initQuantumMachine();
	auto qubits = qvm->allocateQubits(4);
	auto cbits = qvm->allocateCBits(4);
	QProg prog;

	prog << H(qubits[0])
		<< H(qubits[1])
		<< H(qubits[2])
		<< H(qubits[3])
		<< MeasureAll(qubits, cbits);

	auto result = runWithConfiguration(prog, cbits, 1000);
	for (auto &val : result)
	{
		std::cout << val.first << ", " << val.second << std::endl;
	}

	destroyQuantumMachine(qvm);

	return 0;
}