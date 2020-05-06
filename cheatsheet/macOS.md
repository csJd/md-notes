# MY macOS CHEAT SHEET

## Online res

* [Zhihu：macOS (OS X) 有哪些常用的快捷键？](https://www.zhihu.com/question/20021861)
* [OverAPI Cheat sheet](http://www.extensions.in.th/post/rescue/OSX_KeyCombo_Reference_Guide.pdf)
* [Office 字体](https://github.com/guorenxi/MacFonts) [2](https://bbs.feng.com/read-htm-tid-11828177.html)

## MOST WANTED

* ⌘ ⌃ ␣ : 🤗

* ⌃ ⇧ ⌘ 4 : Screen crop

## Tips

* Setting languange for an APP
  ```defaults write com.tencent.qq  AppleLanguages '("zh_CN")'```

* Enable key-repeating for an APP
  ```defaults write com.microsoft.VSCode ApplePressAndHoldEnabled -bool false```

* [Add Sublime text to right click](https://gist.github.com/idleberg/fc0df222e1df258d525d704042d72582)

* Disable dark mode for an APP
  ```defaults write com.google.Chrome NSRequiresAquaSystemAppearance -bool true```

* Disable .DS_Store generate
  ```defaults write com.apple.desktopservices DSDontWriteNetworkStores -bool true```
  ```defaults write com.apple.desktopservices DSDontWriteUSBStores -bool true```

* Disable spotlight for external disk
  ```sudo touch /Volumes/your_volume_name_here/.metadata_never_index```
