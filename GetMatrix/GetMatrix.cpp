#include "Core/QPanda.h"
#include "Core/Utilities/QCircuitInfo.h"
USING_QPANDA

int main(void)
{
	auto qvm = initQuantumMachine(QMachineType::CPU);
	auto qubits = qvm->allocateQubits(2);
	auto cbits = qvm->allocateCBits(2);
	auto prog = createEmptyQProg();
	prog << H(qubits[1])
		<< CNOT(qubits[0], qubits[1])
		<< H(qubits[1]);

	auto cir_Matrix = getMatrix(prog);

	destroyQuantumMachine(qvm);

	return 0;
}