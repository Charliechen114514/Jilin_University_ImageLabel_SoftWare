# JLU_Label_Software

:flags:  `Latest Version: Format v1.1.0(Updated in Aug 20th)`

​		`This project is expected to compiled in Qt6.6.0 or any other neighbored versions of Qt, by using MSVC2019 Compiler to compile it`

​		`Revelant libs of Opencv has already been provided in Source code(Only Version v1.1.0 or further ones may be required, v1.0.0 has no need to compile with linking revelant Opencv libs)`

```
libs in ./JLU_Label_SoftWare/Source_Code/Format v1.1.0/libs/
```

​		`My first Qt project LOL, coding for 114514 seconds and debugging 1919810 times to made such a ... shit?`

​		` You can commit bugs to this email:> chengh1922@jlu.edu.cn, authors will solve it as soon as possible(IF POSSIBLE)`

## Guidance

### Quick Key Sequence Previewed

​		`Here is a sequence of quick keys`

```
Current supportive and available quick key(Available Right now!)

MainWindow
1. Open a picture 				Ctrl + O
2. Import a directory of pictures Ctrl + Shift + D
3. view next one 				-> or D
4. view previous one 			<- or A
5. switch Pictures 				Ctrl + Alt + P
6. switch Directory 			Ctrl + Alt+ D
7. Delete the cyrrent Picture 	 Ctrl + D
8. Manage your label 			Ctrl + L

Manually Label
1. switch to the next one		-> or D
2. switch to the previous one	<- or  A
(BE COUTIOUS, hereby we don't allow adjust pictures anymore!)

Actual Label Window
1. to Next picture (If you choice to select the default saving path you referred on the query dialog shown when you enter the ALW, no query of saving dialog will be ejected(anyway, I dislike using 'show!')) ->
2. save Pcitures and dataLabels Ctrl + S
3. remove the last labeling Ctrl + Z

Auto Label(Sequenced Consistent pictures set)Window
1. to nect picture ->
```

### `start `

:arrow_right:` Import Pictures ( Or directory )`

​		`This software support to import pictures in variety way: Single Pic importing , Directory Pics Importing and switch pictures and Directory`

```
REMINDER: Ctrl + O can add pic, while Ctrl + shift + D add dirs
```

```
About Picture Format: You can change the Supportive and Available Picture's Format Set by recoding the MACRO: ALLOWING_PICDIR_TYPE in MainWindow.h! And do not forget to recoding ALLOWING_PICDIR_TYPE as well, which is using in QFileDialog(IF YOU DON't, the QFileDialog won't show the NEW_ADDED TYPE!)
```

```
this software can support loading at least 2000 pics at one time!
```

:warning:

```
switch directory may erase all pictures ! if you just want to add, try use "add dir"
```

:arrow_right:` Delete Pictures`

​		`If you want to delete current Images, you can delete it`

```
Quick Key: delete current Pics: Ctrl + D
```

​		`or you can simply click the "Delete Image" Button`

:arrow_right:`manage Labels`

​		`Of course you can manage labels!`

​		`Click the "Manage Label" menu in the menu bar or just click "adjust labels" button on the mainWindow.`

​		`Quick Key is also available `

```
Manage Label: Ctrl + L
```

 :arrow_right: `help`

​		`You can check revelant Quick Sequence on help menu`

:arrow_right: `Advanced Settings`

​		`You can set Labels Import Seperator, whch is using in Labels Import, Defaultly, our seperator is `

```
;
```

​		`You can switch it to other type`

​		`in FORMAT V1.1.0, there is also a advanced section called "Set AutoSave Path"`

### `View Pictures`

​		`You can click the "Next one" or "Previous one" any how! But there is a recommended way by using quick key`

```
view next one 				-> or D
view previous one 			<- or A
```

 		`If you ensure the picture list you import is acceptable, you can move on to manually label: ALL Pictures on the lists will be sent to Manually Label Windows. Please Verify your adjustment before moving on`

## `Label Managements`

​		`Label Management is a section of this software, The Labels are synchronoic in all windows! To operate the labels, I will take the MainWindow API as example`

:arrow_right: `Add Labels`

​		`We only support English Label import, ADD ENSURE ADDING AFTER YOU IMPORT new labels, you can erase adding by clciking "Regret Adding!", After click, you are suppose to Click the added labels ( For the shared API)`

:arrow_right:` Delete Labels`

​		`Tick the label you wanna delete, BE CAUTIOUS:`

```
WE ONLY ACCEPT DELETING ONE LABEL PER TIME!
```

```
ALL CHANGES AER synchronoic
```

:arrow_right: `IMPORT LABELS`

​		`You can select importing labels in the menu bar, `

```
BUT IN CURRENT VERSION YOU HAVE TO LOCATE TO TARGET DIRECTORY AND THEN CODE THE TXT INSTEAD OF SELECTING! 
```

​		`In this case, you can write the labels files, by using a format of writing.`

```
label[SEPERATOR]label[SEPERATOR]label[SEPERATOR]...
```

​		`If you haven't change the seperator,  you can write config file liek this`

```
watermalon;apple;people;book
```

<<<<<<< HEAD
## `Manually label`
=======
## Manually label
>>>>>>> 053f866e5a6298fe6c7eee856580c83c689bc6ab

​		`CLICK MANUALLY LABLE, and you can manage the detailed labels. To Enter the manually window, ensure pictures have been loaded previously, or, Some Error will be ejected!`

​		`Here, you can adjust labels, make a settings of pen's style(colors and widths)`

## `Formal Label`

​		`Click Labels NOW button, we will labels the pictures at the front of the file`

​		`Every time you enter the window, softeare will query the paths of saving. Please be cautious of selecting paths`

### `labeling`

​		`Two vertically crossing line are guide line! It will help you locate the location of your mosue. You can wheel up and down to adjust the width of the guide line.`

​		`Click! and then you labels`

​		`Sometimes, you may find unsuitable of some point's position, you can remove it by pressing "Remove Back the last point" or press quick key Ctrl + <-`

​		`If you don't refer the auto save path, every time you finish your labeling, the software will ask for whether there is a need of saving and save for where.`

​		`Or, if you selected the default saving place, simply press -> to continue your labeling`

​		`If you want to remove a whole ploy, you can click "Remove Poly" or press quick key "Ctrl + Z"`

### `styles selecting`

​		`you can select pen style, just have fun!`

```
the styles of pen is GLOBAL
```

### ` change the method of labeling`

​		`You can change the label method when you are labeling, but all data in this picture will be erased!`

<<<<<<< HEAD
### `[[In version v1.1.1]] Manupulate historical data accessible`

​		`In version v1.1.0, Rolling pictures up and down in Formally Label Windows to change the data has been accessible. In this case, if you are really unsatisfied of your labeling, just simply press <- or A and then press Ctrl + Z altogather to roll back  the data.(It is worth noticing that: I fixed the strange refection between the Quick Key A and move on, instead, I change it back to the normal reflection <- and -> with roll back and forth )`

### `Save(unrefered to savePath)`
=======
### Save(unrefered to savePath)
>>>>>>> 053f866e5a6298fe6c7eee856580c83c689bc6ab

​		If you don't specify the path when you start annotating, then by default you don't autosave. Then, after each image is marked, it will ask you for the path and location of the save, as well as the file name (this is done for compatibility with the format, you can make the format specification yourself when naming)

​		As you can see, this software will prompt you for your saved address!

### `Save (refered to savePath)`

​		`Simply click the next one`

### `Save for data`

​		`In this version, software is supportive for change the save method including STANDARD METHOD AND YOLO METHOD, if you want to redefine the method , just rewrite the writingMethod() function in class curPicForLabeling_MainWindow`

## `Auto Label`

:warning::

```
Never use this function in a path including other no-English Path!
```

### `Continuous gallery annotations`

​		`Written on the front: This auto-annotation update is experimental and has not yet been better integrated by the auto-annotation! First of all, automatic labeling only supports one tag for one object tag, in other words, **It does not support more than two object markers**.**It does not support more than two object markers** **It does not support more than two object markers** **It does not support more than two object markers** Better extensions will be added again in the next update.`

​		`This feature was developed around Aug 17th. It uses the opencv tracker. It is worth noting that we use a traditional visual algorithm, and it is difficult to ensure that what is automatically labeled is accurate. From this, it only acts as a kind of auxiliary marker! It Only suits for a picture sets that shows well of bjects that characterize continuous motion.`

**:warning:: `Before you start annotating, be sure to select the location where to save it (down to the folder!) ** Otherwise, there may be a failure to save.`

**:warning:: `Before you start labeling, be sure to choose your label! And make sure you only have one tag in your tag list!** (sad)`

​		`You can then click Auto-label Gallery to mark it`

## `Ensure the ROI Rect`

​		`Our markings must be tracked only after you have manually determined the ROI Rect! Quite Easy to select ROI:  just click in the window, the first click to determine the upper left corner point, the second click to determine the lower right corner point. Once you have determined the ROI, you can proceed to the next annotation.`

## Labeling

​		`If the precious of autoLable is satisfying, you can click` :arrow_right: `key to move on, Files will export automatically with a format of:`

```
${curPixelMapIndex}_AfterAutoLabel.txt
```

​		`If the savePath is accessible, data files will exsit in the specified path`

## ReCorrect ROI

​		`Find the Rect is unsatisfying? Recorrect it!(Same way to rectify the ROI), then a new track will begin!`

## :warning: defect

​		`As an experimental content, it is worth noting that the automatic annotation will not fall back to the previous one, and if you find that your annotation is not satisfactory, you can only re-annotate it in v1.1.0 and cannot edit it.`