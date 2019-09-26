#include "Core/QPanda.h"
USING_QPANDA

int main(void)
{
	auto qvm = initQuantumMachine();
	auto qubits = qvm->allocateQubits(4);
	auto prog = CreateEmptyQProg();
	prog << H(qubits[0]) << CNOT(qubits[0], qubits[1])
		<< iSWAP(qubits[1], qubits[2]) << RX(qubits[3], PI / 4);

	auto time = getQProgClockCycle(prog, qvm);
	std::cout << "clockCycle : " << time << std::endl;

	destroyQuantumMachine(qvm);

	return 0;
}