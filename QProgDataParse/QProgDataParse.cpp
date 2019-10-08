#include "Core/QPanda.h"
#include "Core/Utilities/base64.hpp"

USING_QPANDA

int main(void)
{
	auto qvm = initQuantumMachine();
	QProg parseProg;
	QVec qubits_parse;
	std::vector<ClassicalCondition> cbits_parse;

	std::string data_str = "AAAAAAQAAAAEAAAABAAAAA4AAQAAAAAAJAACAAAAAQAkAAMAAQACACQABAACAAMA";
	auto data = Base64::decode(data_str.data(), data_str.size());
	transformBinaryDataToQProg(qvm, data, qubits_parse, cbits_parse, parseProg);

	auto result_parse = probRunTupleList(parseProg, qubits_parse);
	for (auto &val : result_parse)
	{
		std::cout << val.first << ", " << val.second << std::endl;
	}

	destroyQuantumMachine(qvm);
	return 0;
}