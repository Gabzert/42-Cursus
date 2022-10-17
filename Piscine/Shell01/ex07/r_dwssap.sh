cat /etc/passwd | cut -f 1 -d ':'| awk 'NR%2==0' | rev | sort -r |awk -v var1="$FT_LINE1" -v var2="$FT_LINE2" 'NR>=var1&&NR<=var2' | awk '{gsub(/$/,", ")}1' | tr -d "\n" | sed "s/..$/./"

