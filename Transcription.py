'''
This only works for the exon strands, and would require a lot more work to edit grabbing introns
or even trying to replicate would require more time, but it does a good job showing it.
'''

def Convert(string):
    list1=[]
    list1[:0]=string
    return list1

def listToString(s):
    str1 = ""  
    for ele in s: 
        str1 += ele  
    return str1

def listToSentence(r):
    str2=" "
    for ele in r:
        ele += str2
    return str2

def func(seq, n):
    return [''.join(item) for item in zip(*[seq[n:] for n in range(n)])]

coding=Convert(input("Input the coding strand:"))

template=[]
for item in coding:
    if item=="A" or item=="a":
        template.append("T")
    elif item=="T" or item=="t":
        template.append("A")
    elif item=="G" or item=="g":
        template.append("C")
    elif item=="C" or item=="c":
        template.append("G")

mRNA=[]
for item in template:
    if item=="A" or item=="a":
        mRNA.append("U")
    elif item=="T" or item=="t":
        mRNA.append("A")
    elif item=="G" or item=="g":
        mRNA.append("C")
    elif item=="C" or item=="c":
        mRNA.append("G")

protein=[]
for item in func(mRNA,3):
    if item=="AUG":
        protein.append("Met")
    elif item=="UGG":
        protein.append("Trp")
    elif item=="UAA":
        protein.append("Ochre")
    elif item=="UAG":
        protein.append("Amber")
    elif item=="UGA":
        protein.append("Opal")
    elif item=="UUU" or item=="UUC":
        protein.append("Phe")
    elif item=="UAU" or item=="UAC":
        protein.append("Tyr")
    elif item=="CAU" or item=="CAC":
        protein.append("His")
    elif item=="CAA" or item=="CAG":
        protein.append("Gln")
    elif item=="AAU" or item=="AAC":
        protein.append("Asn")
    elif item=="AAA" or item=="AAG":
        protein.append("Lys")
    elif item=="GAU" or item=="GAC":
        protein.append("Asp")
    elif item=="GAA" or item=="GAG":
        protein.append("Glu")
    elif item=="UGU" or item=="UGC":
        protein.append("Cys")
    elif item=="AUU" or item=="AUC" or item=="AUA":
        protein.append("Ileu")
    elif item=="GUU" or item=="GUC" or item=="GUA" or item=="GUG":
        protein.append("Val")
    elif item=="CCU" or item=="CCC" or item=="CCA" or item=="CCG":
        protein.append("Pro")
    elif item=="ACU" or item=="ACC" or item=="ACA" or item=="ACG":
        protein.append("Thr")
    elif item=="GCU" or item=="GCC" or item=="GCA" or item=="GCG":
        protein.append("Ala")
    elif item=="GGU" or item=="GGC" or item=="GGA" or item=="GGG":
        protein.append("Gly")
    elif item=="UUA" or item=="UUG" or item=="CUU" or item=="CUC" or item=="CUA" or item=="CUG":
        protein.append("Leu")
    elif item=="UCU" or item=="UCC" or item=="UCA" or item=="UCG" or item=="AGU" or item=="AGC":
        protein.append("Ser")
    elif item=="CGU" or item=="CGC" or item=="CGA" or item=="CGG" or item=="AGA"  or item=="AGG":
        protein.append("Arg")

protein2=[]
protein2.append(protein[0::3])

print(listToString(template))
print(listToString(mRNA))
print(' '.join([str(elem) for elem in protein2]))