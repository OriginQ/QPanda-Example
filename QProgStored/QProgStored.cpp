#include "Core/QPanda.h"
#include "Core/Utilities/base64.hpp"
USING_QPANDA

int main(void)
{
	auto qvm_store = initQuantumMachine();
	auto qubits = qvm_store->allocateQubits(4);
	auto cbits = qvm_store->allocateCBits(4);
	cbits[0].setValue(0);

	QProg prog;
	prog << H(qubits[0]) << CNOT(qubits[0], qubits[1])
		<< CNOT(qubits[1], qubits[2])
		<< CNOT(qubits[2], qubits[3])
		;
	auto data = transformQProgToBinary(prog, qvm_store);
	auto base64_data = Base64::encode(data.data(), data.size()); //the resulting binary data is encoded in base64
	std::string data_str(base64_data.begin(), base64_data.end());
	std::cout << data_str << std::endl;

	destroyQuantumMachine(qvm_store);

	return 0;
}