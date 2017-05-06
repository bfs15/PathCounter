N=2

echo "strict digraph exemplo {"

for ((i=N; i>0; i--))
do
	echo
	# echo -e "\tI$i [I=1];"
	# echo -e "\tK$i [K=1];"
	# echo -e "\tA$i [A=1];"
	# echo

	echo -e "\tA$i -> B$i;"
	echo -e "\tA$i -> C$i;"
	echo -e "\tC$i -> D$i;"
	echo -e "\tC$i -> I$(($i-1));"
	echo -e "\tB$i -> I$(($i-1));"
	echo -e "\tB$i -> A$(($i-1));"
	echo -e "\tD$i -> A$(($i-1));"
	echo -e "\tD$i -> K$(($i-1));"
	echo -e "\tD$i -> J$i;"
	echo -e "\tI$i -> F$i;"
	echo -e "\tI$i -> G$i;"
	echo -e "\tG$i -> D$i;"
	echo -e "\tF$i -> D$i;"
	echo -e "\tK$i -> J$i;"
	echo -e "\tJ$i -> A$(($i-1));"
	echo -e "\tJ$i -> K$(($i-1));"
done

echo
echo -e "\tI$i [Z=1];"
echo -e "\tA$i [X=1];"
echo -e "\tK$i [Y=1];"

echo "}"
# strict digraph exemplo {
# 	A1 -> B1;
# 	A1 -> C1;
# 	C1 -> D1;
# 	C1 -> I0;
# 	B1 -> I0;
# 	B1 -> A0;
# 	D1 -> A0;
# 	D1 -> K0;
# 	D1 -> J1;
# 	I1 -> F1;
# 	I1 -> G1;
# 	G1 -> D1;
# 	F1 -> D1;
# 	K1 -> J1;
# 	J1 -> A0;
# 	J1 -> K0;
#
# 	X0 [X=1];
# 	Y0 [Y=1];
# 	Z0 [Z=1];
#
# 	A0 -> B0;
# 	A0 -> C0;
# 	C0 -> D0;
# 	C0 -> Z0;
# 	B0 -> Z0;
# 	B0 -> X0;
# 	D0 -> X0;
# 	D0 -> Y0;
# 	D0 -> J0;
# 	I0 -> F0;
# 	I0 -> G0;
# 	G0 -> D0;
# 	F0 -> D0;
# 	K0 -> J0;
# 	J0 -> X0;
# 	J0 -> Y0;
# }
