echo
echo "we should see 2 volumes"
echo

docker volume ls

echo
echo "hit enter to continue"
read

echo
echo "the path should be /home/$USER/data/"
echo

docker inspect $(docker volume ls -q)

echo
echo "hit read to continue"
echo
read
