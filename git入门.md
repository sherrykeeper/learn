# 准备工作
## 关联一个远程库
	git remote add origin 网址

## 查看git指向的远程库
	git remote -v		// 查看版本库指向的远程仓库
	
## 更改git指向的远程库
	git remote set-url origin (URL)		// 更改指向的远程仓库
	
## 同步远程仓库和本地仓库
	git pull --rebase origin master
本地仓库需要是空的。 否则之间存在的本地文件将不能够add到暂存区

# 版本穿梭
git允许我们在不同的版本之间进行穿梭。

HEAD指向的版本就是当前版本
## 版本回退
	回退上一个版本：git reset --hard HEAD^
	
	回退上上个版本：git reset --hard HEAD^^
	
	也可以写成 git reset --hard HEAD~2

**git reflog** 用来记录每一次命令

使用git reset --hard commit_id

	穿梭前，用git log查看提交历史，以便确定要回退到哪个版本
	
	要重返未来，用git reflog 查看历史命令，以便确定要回到未来的那个版本
	
	使用 git status 查看 git的状态



## 撤销上一次修改
这里有3种情况：

1. 是readme.txt自修改后还没有被放到暂存区，现在，撤销修改就回到和版本库一模一样的状态；    操作：git checkout -- readme.txt    把readme.txt文件在工作区的修改全部撤销

2. 是readme.txt已经添加到暂存区后，又作了修改，现在，撤销修改就回到添加到暂存区后的状态。 git reset HEAD <file> 把暂存区的修改撤销掉（unstage）   -- 把暂存区的修改，返回到工作区， 再通过 git checkout -- 文件   丢弃工作区的修改

3. 修改后的文件已经提交到了版本库，但是没有推送到远程库。

版本回退：
git reset 既可以回退版本，也可以把暂存区的修改回退到工作区


## 删除操作：
已经将文件提交到了版本区， 删除了本地工作区的文件；
如果真的要删除该文件，则可以将版本区的文件也删除   git rm 文件名
如果是误删，想要恢复:  git checkout -- 文件名

## 分支
创建并切换分支

	git checkout -b dev

	= 
	git branch dev
	git checkout dev

查看当前分支

	git branch			// git branch命令会列出所有分支，当前分支前面会标一个*号。


创建分支

	git branch <name>

合并某分支到当前分支

	git merge <name>        实现将分支的内容与name 分支合并
因为创建、合并和删除分支非常快，所以Git鼓励你使用分支完成某个任务，合并后再删掉分支，这和直接在master分支上工作效果是一样的，但过程更安全。

创建并切换到新的dev分支：

	git switch -c dev
直接切换到已有的master分支

	git switch master