#include "Core/QPanda.h"
USING_QPANDA

int main(void)
{
	// Single quantum gate validity verification
	std::vector<std::string> single_gate;
	std::vector<std::string> valid_single_gate; 
	single_gate.push_back("T");
	single_gate.push_back("H");
	single_gate.push_back("S");

	auto single_gate_type = validateSingleQGateType(single_gate, valid_single_gate);

	std::cout << "SingleGateTransferType: " << single_gate_type << std::endl;
	for (auto &val : valid_single_gate)
	{
		std::cout << val << " ";
	}
	std::cout << std::endl;

	// Double quantum gate validity verification
	std::vector<std::string> double_gate;
	std::vector<std::string> valid_double_gate; 
	double_gate.push_back("CNOT");
	double_gate.push_back("SWAP");
	double_gate.push_back("CZ");


	auto double_gate_type = validateDoubleQGateType(double_gate, valid_double_gate);

	std::cout << "doubleGateTransferType: " << double_gate_type << std::endl;
	for (auto &val : valid_double_gate)
	{
		std::cout << val << " ";
	}
	std::cout << std::endl;

	return 0;
}