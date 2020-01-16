if [ "$USER" == 'grandinbenjamin' ]; then
  echo "Bienvenue $USER"
  if [ "$#" -eq "0" ]; then
    echo "No argument supplied, need 3"
  else
		FILESIZE=$(stat -f "%z" "$4")

		echo "size: $FILESIZE"
		if ! [[ "$FILESIZE" =~ ^[0-9]+$ ]]; then
					echo "$FILESIZE doesn't exist"
			elif [ "$FILESIZE" -gt "$5" ]; then
				echo "$FILESIZE is larger than $5"

		fi

		ls "$1"

	fi
fi

