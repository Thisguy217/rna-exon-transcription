#include <iostream>
#include <string>
#include <vector>
#include <chrono>
using namespace std::chrono;

std::vector<std::string> ProteinSynthaseFunction(const std::string& inputString);
std::string RegularExpressionFormat(const std::string& inputString);
std::string ConvertToRNA(const std::string& inputString);

int main()
{
    std::string templateStrand;
    std::cout << "Enter coding strand, this will skip the template strand: ";
    getline(std::cin, templateStrand);
    std::cout << std::endl;

    auto start = high_resolution_clock::now();

    //std::cout << templateStrand << std::endl;
    std::string regexStrand = RegularExpressionFormat(templateStrand);
    //std::cout << regexStrand << std::endl;

    std::string mRNA = ConvertToRNA(regexStrand);
    //std::cout << mRNA << std::endl;

    std::vector<std::string> AAChain = ProteinSynthaseFunction(mRNA);
    for (const std::string& AminoAcid : AAChain)
    {
        std::cout << AminoAcid << std::endl;
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << duration.count() << " microseconds" << std::endl;
    return 0;
}

std::string RegularExpressionFormat(const std::string& inputString)
{
    std::string temp;
    for (char letter : inputString)
    {
        if (letter == 'A' || letter == 'a' || letter == 'C' || letter == 'c' || letter == 'G' || letter == 'g' || letter == 'T' || letter == 't' || letter == 'U' || letter == 'u')
        {
            if (letter >= 97)
            {
                letter -= 32;
            }
            temp += letter;
        }
    }
    return temp;
}

std::string ConvertToRNA(const std::string& inputString)
{
    std::string temp;
    for (char charSwap : inputString)
    {
        if (charSwap == 'T')
        {
            temp += 'U';
        }
        else
        {
            temp += charSwap;
        }
    }
    return temp;
}

std::vector<std::string> ProteinSynthaseFunction(const std::string& inputString)
{
    std::vector<std::string> aminoAcidChain;
    std::vector<std::string> tempVector;
    std::string temp;
    for (char i : inputString)
    {
        temp += i;
        if (temp.length() >= 3)
        {
            tempVector.emplace_back( temp );

            temp = "";
        }
    }

    for (const std::string& item : tempVector)
    {
        if (item == "AUG")
        {
            aminoAcidChain.emplace_back("Met");
        }
        else if (item == "UGG")
        {
            aminoAcidChain.emplace_back("Trp");
        }
        else if (item == "UAA")
        {
            aminoAcidChain.emplace_back("Ochre");
        }
        else if (item == "UAG")
        {
            aminoAcidChain.emplace_back("Amber");
        }
        else if (item == "UGA")
        {
            aminoAcidChain.emplace_back("Opal");
        }
        else if (item == "UUU" || item == "UUC")
        {
            aminoAcidChain.emplace_back("Phe");
        }
        else if (item == "UAU" || item == "UAC")
        {
            aminoAcidChain.emplace_back("Tyr");
        }
        else if (item == "CAU" || item == "CAC")
        {
            aminoAcidChain.emplace_back("His");
        }
        else if (item == "CAA" || item == "CAG")
        {
            aminoAcidChain.emplace_back("Gln");
        }
        else if (item == "AAU" || item == "AAC")
        {
            aminoAcidChain.emplace_back("Asn");
        }
        else if (item == "AAA" || item == "AAG")
        {
            aminoAcidChain.emplace_back("Lys");
        }
        else if (item == "GAU" || item == "GAC")
        {
            aminoAcidChain.emplace_back("Asp");
        }
        else if (item == "GAA" || item == "GAG")
        {
            aminoAcidChain.emplace_back("Glu");
        }
        else if (item == "UGU" || item == "UGC")
        {
            aminoAcidChain.emplace_back("Cys");
        }
        else if (item == "AUU" || item == "AUC" || item == "AUA")
        {
            aminoAcidChain.emplace_back("Ileu");
        }
        else if (item == "GUU" || item == "GUC" || item == "GUA" || item == "GUG")
        {
            aminoAcidChain.emplace_back("Val");
        }
        else if (item == "CCU" || item == "CCC" || item == "CCA" || item == "CCG")
        {
            aminoAcidChain.emplace_back("Pro");
        }
        else if (item == "ACU" || item == "ACC" || item == "ACA" || item == "ACG")
        {
            aminoAcidChain.emplace_back("Thr");
        }
        else if (item == "GCU" || item == "GCC" || item == "GCA" || item == "GCG")
        {
            aminoAcidChain.emplace_back("Ala");
        }
        else if (item == "GGU" || item == "GGC" || item == "GGA" || item == "GGG")
        {
            aminoAcidChain.emplace_back("Gly");
        }
        else if (item == "UUA" || item == "UUG" || item == "CUU" || item == "CUC" || item == "CUA" || item == "CUG")
        {
            aminoAcidChain.emplace_back("Leu");
        }
        else if (item == "UCU" || item == "UCC" || item == "UCA" || item == "UCG" || item == "AGU" || item == "AGC")
        {
            aminoAcidChain.emplace_back("Ser");
        }
        else if (item == "CGU" || item == "CGC" || item == "CGA" || item == "CGG" || item == "AGA"  || item == "AGG")
        {
            aminoAcidChain.emplace_back("Arg");
        }
    }
return aminoAcidChain;
}
