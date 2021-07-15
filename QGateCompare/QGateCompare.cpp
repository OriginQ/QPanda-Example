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
		<< iSWAP(qubits[2], qubits[3])
		<< Measure(qubits[1], cbits[0]);

	std::vector<std::string> single_gates = { "H" }; 
	std::vector<std::string> double_gates = { "CNOT" };
	std::vector<std::vector<std::string>> gates = { single_gates, double_gates };

	size_t num = getUnsupportQGateNum(prog, gates);
	std::cout << "unsupport QGate num: " << num << std::endl;
	finalize();

	return 0;
}