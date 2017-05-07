N=2

echo "strict digraph exemplo {"

for ((i=N; i>0; i--))
do
	echo
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
