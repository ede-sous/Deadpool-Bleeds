
echo "source $HOME/.brewconfig.zsh" >> $HOME/.bashrc
echo "source $HOME/.brewconfig.zsh" >> $HOME/.zshrc

curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh
