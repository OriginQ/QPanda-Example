#include "Core/QPanda.h"
USING_QPANDA


int main(void)
{
	auto qvm = initQuantumMachine(QMachineType::CPU);
	auto qubits = qvm->allocateQubits(4);
	auto cbits = qvm->allocateCBits(4);
	QProg prog;
	prog << X(qubits[0])
		<< Y(qubits[1])
		<< H(qubits[2])
		<< RX(qubits[3], 3.14)
		<< Measure(qubits[0], cbits[0]);

	std::string instructions = transformQProgToQuil(prog, qvm);
	std::cout << instructions << std::endl;
	destroyQuantumMachine(qvm);
	return 0;
}