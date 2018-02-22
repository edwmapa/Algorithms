#Simple script. Adds all, commits, and push it.
MESSAGE
echo "---Simple Commit---"
sleep .2
echo "> commit message> "
read MESSAGE
git add --all && git commit -m $MESSAGE

git push origin master || echo "Can't push to master, check manually"
