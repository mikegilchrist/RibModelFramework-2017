#ifndef RFPTRACE_H
#define RFPTRACE_H

#include <iostream>
#include <vector>
#include <cctype>
#include "../base/Trace.h"
class RFPTrace: public Trace {
	private:
		std::vector<std::vector<std::vector<double>>>alphaParameterTrace; //order: mutationcategoy, numparam, samples
		std::vector<std::vector<std::vector<double>>> lambdaPrimeParameterTrace;//order: selectioncategoy, numparam, samples

		public:
		//Constructor & Destructors
		RFPTrace();

		//Init functions
		void initAllTraces(unsigned samples, unsigned num_genes, unsigned numMutationCategories,
				unsigned numSelectionCategories, unsigned numParam, unsigned numMixtures, std::vector<mixtureDefinition> &_categories);
		void initRFPTraces(unsigned samples, unsigned numMutationCategories, unsigned numSelectionCategories, unsigned numParam);
		void initAlphaParameterTrace(unsigned samples, unsigned numMutationCategories, unsigned numParam);
		void initLambdaPrimeParameterTrace(unsigned samples, unsigned numSelectionCategories, unsigned numParam);

		//Getter functions
		std::vector<double> getAlphaParameterTraceByMixtureElementForCodon(unsigned mixtureElement, std::string& codon);
		std::vector<double> getLambdaPrimeParameterTraceByMixtureElementForCodon(unsigned mixtureElement, std::string& codon);

		unsigned getAlphaCategory(unsigned mixtureElement)
		{	return categories->at(mixtureElement).delM;}
		unsigned getLambdaPrimeCategory(unsigned mixtureElement)
		{	return categories->at(mixtureElement).delEta;}

		//Update functions	
		void updateCodonSpecificParameterTrace(unsigned sample, std::string codon, std::vector<std::vector<double>> &curAlpParam, std::vector<std::vector<double>> &curLmPriParam);

		//R WRAPPER FUNCTIONS

		//Getter functions
		std::vector<double> getMutationParameterTraceByMixtureElementForCodonR(unsigned mixtureElement, std::string& codon);//R WRAPPER
		std::vector<double> getSelectionParameterTraceByMixtureElementForCodonR(unsigned mixtureElement, std::string& codon);//R WRAPPER
	};

#endif //RFPTRACE_H
