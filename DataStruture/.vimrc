set number

syntax on	"语法高亮	
set showmode	"在底部显示，当前处于命令模式还是插入模式
set showcmd	"命令模式下，在底部显示，当前键入的指令
set mouse=a	"支持使用鼠标
set encoding=utf-8	"使用 utf-8 编码
set t_Co=256	"启用256色
filetype indent on	"开启文件类型检查，并且载入与该类型对应的缩进规则

set autoindent	"按下回车键后，下一行的缩进会自动跟上一行的缩进保持一致
set tabstop=4	"按下 Tab 键时，Vim 显示的空格数
set shiftwidth=4
"set expandtab	"设置自动将 Tab 转为空格
"set softtabstop=2	"Tab 转为多少个空格

"set relativenumber	"显示光标所在的当前行的行号
set cursorline	"光标所在的当前行高亮
set textwidth=80	"设置行宽，即一行显示多少个字符
set wrap	"自动折行，即太长的行分成几行显示
set linebreak	"只有遇到指定的符号（比如空格、连词号和其他标点符号），才发生折行。也就是说，不会在单词内部折行。

set ignorecase	"搜索时忽略大小写

set autoread	"打开文件监视。如果在编辑过程中文件发生外部改变（比如被别的编辑器编辑了），就会发出提示

set wildmenu	"底部操作指令按下 Tab 键自动补全
set wildmode=longest:list,full

function! CleverTab()
	if strpart( getline('.'), 0, col('.')-1 ) =~ '^\s*$'
		return "\<Tab>"
	else
		return "\<C-N>"
	endif
endfunction
inoremap <Tab> <C-R>=CleverTab()<CR>

