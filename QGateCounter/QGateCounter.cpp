#include "QPanda.h"
USING_QPANDA

int main(void)
{
	init();
	auto qubits = qAllocMany(4);
	auto cbits = cAllocMany(4);

	QProg prog;
	prog << X(qubits[0])
		<< Y(qubits[1])
		<< H(qubits[0])
		<< RX(qubits[0], 3.14)
		<< Measure(qubits[1], cbits[0]);

	size_t num = getQGateNum(prog);
	std::cout << "QGate number: " << num << std::endl;
	finalize();

	return 0;
}