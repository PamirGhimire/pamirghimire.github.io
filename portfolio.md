---
layout: default
title: Portfolio
permalink: /portfolio/
---

<h2>Augmented Reality in Image Guided Surgery</h2>
![EnCoV_AR](/assets/projects_portfolio/encov.png){:class="img-responsive"}

Ported to C++ (in Linux) previously developed research code (in MATLAB) for Non-Rigid 3D-3D Registration of a pre-operative organ model (textureless 3D mesh) obtained from CT scans with an intraoperative model reconstructed from images captured during the surgery. I implemented modules for voxelisation and tetrahedralization of 3D meshes, and ICP based 3d-3d registration. The voxelisation algorithm was my own proposition and implemetation. Open source C++ libraries like Boost, Eigen, OpenCV, and Assimp were used, and development was version-controlled using Git.<br>

[> Video : Real-time AR using the Sotware platform](https://www.youtube.com/watch?v=s39FkqLdQT4&feature=youtu.be){:target="_blank"}

<hr><br>

<h2>Visual Servoing of Turtlebot using ROS</h2>
![Visual_Servoing](/assets/projects_portfolio/visualServoing.png){:class="img-responsive"}

Implemented image-points-based and pose-based visual servoing on Turtlebot 2 platform, using ROS and ViSP library. Gazebo was used for prototyping the implementations.
​
Pose based approach was implemented using a QR tag whose pose was automatically estimated in robot’s frame (using ViSP Autotracker).
The points-based approach required the user to manually select 4 centers in a known printed pattern of filled dots (blobs).
​
The visual servoing (fine positioning) task was also automatically coordinated with a navigation task using a Multi-master setup in ROS.

[> Project Repo : GitHub](https://github.com/PamirGhimire/visualServoing_ROSProject){:target="_blank"}<br>
[> Video: Gazebo Demo](https://www.youtube.com/watch?v=qCdgKvE52iY){:target="_blank"}<br>
[> Video: Pose Based](https://www.youtube.com/watch?v=K4BQ3v-MSrs){:target="_blank"}<br>
[> Video: Image Points Based](https://www.youtube.com/watch?v=yDBamqhc0QQ){:target="_blank"}<br>
[> Video : Navigation + Visual Servoing](https://www.youtube.com/watch?v=hZTU4JiTiyA&feature=youtu.be){:target="_blank"}<br>

<hr><br>

<h2>Hololens for Teaching Radiation Safety in Hybrid Operating Room</h2>
![Hololens](/assets/projects_portfolio/hololens.png){:class="img-responsive"}
I developed a set of apps for Microsoft Hololens during a 3 months internship at research group CAMMA (Computational Analysis and Modelling  of Medical Activities) based in Strasbourg, France. The goal of the internship was to develop augmented/mixed reality applications for teaching radiation safety in a Hybrid operating room. 
​
Applications were developed under two categories:
a. Augmented/Mixed reality
b. Virtual reality
​
Development work included custom shader development for volume rendering, wireless communication implementation with a linux computer, and interactive UI design using Unity.<br>
​

[> Video: Demo of Developed Apps](https://www.youtube.com/watch?v=lflbEWC5VsA){:target="_blank"}<br>
[> Video: Presentation at European Congress on Radiology, 2017](http://metafusion-a.akamaihd.net/180228_6118_ECR_ECR_2018_Wien/lecture_38931_un.mp4){:target="_blank"}<br>
​
<hr><br>

<h2>Learning Local Descriptors for ComparingRenders with Real Images (MSc Thesis)</h2>
![DeepLearningTF](/assets/projects_portfolio/deepLearningDemo.png){:class="img-responsive"}

<b>Abstract</b> :  We present a method to train a deep network based feature descriptor to extract discriminative local descriptions from renders and corresponding real images with similar viewpoints and geometry. The work was done in context of inspection of mechanical assemblies for which 3D CAD models and approximate poses of the inspection camera were available. The descriptor was trained to best capture geometric features and stay invariant to image domain and rotation. Patch pairs for training the descriptor were extracted in a semi-supervised manner from a small dataset of less than 100 real images and corresponding renders with similar viewpoints which were manually registered to the real images. Due to the small size of training dataset, the descriptor network was initialized with weights from classification training on ImageNet. A two-step training was proposed for addressing the problem of domain shift. The first step,termed ’bootstrapping’, was a classification training to obtain good initial weights for second training step, the triplet-loss training, that provided weights for extracting discriminative embeddings that could be compared using L2-distance. The FPR95 score for the best descriptor was 13.8. ROC curves were plotted for comparing descriptors trained with different configurations. The descriptor was explored for comparing renders and real images through two approaches, first finding local correspondences between them through nearest neighbor matching of descriptors computed at FAST interest points, and second comparing crops of real images and renders by representing them as histograms based on Bag of Visual Words of the learned features. We observed that learning robust cross-domain rotation invariant descriptors is feasible, even with a small dataset, and such features may be of interest for various industrial applications like CAD based visual inspection, tracking, and finely registered augmented reality. To the best of our knowledge,this is the first work that reports learning local descriptors for comparing renders with real images

[> MSc Thesis : ](https://sites.google.com/site/visionindx/my-projects/tensorflow/tf4_convnetoncifar){:target="_blank"}<br>

<hr><br>

<h2>Computer Vision Toolbox - (C++ & OpenCV3.2) and (MATLAB)</h2>
![CVToolbox](/assets/projects_portfolio/seeWithCpp.png){:class="img-responsive"}
The C++ and MATLAB toolboxes are collection of classes and functions respectively on top of which GUIs were built, that allowed the user to perform processing on single images, as well as on (stereo) pair of images, including camera calibration using multiple images.
​
The C++ toolbox was built using OpenCV 3.2. I used a Model-View-Controller (MVC) pattern to design the application. All methods in the toolbox were implemented as encapsulated algorithms, in order to maximize scope of future reusability.<br>

[> GitHub Repo : C++ toolbox](https://github.com/PamirGhimire/seeWithCpp){:target="_blank"}<br>
[> GitHub Repo : MATLAB toolbox](https://github.com/PamirGhimire/seeWithMatlab_cppParallel){:target="_blank"}<br>
[> Video: Demo using C++ toolbox](https://www.youtube.com/watch?v=0kjDgor4Mn0){:target="_blank"}<br>

<hr><br>

<h2>DICOM Manipulation Tool Using MATLAB</h2>
![CVToolbox](/assets/projects_portfolio/dicomGui.png){:class="img-responsive"}
A GUI based application for segmenting prostrate and its regions from CT (Computed Tomography) was developed in this lab work, using MATLAB. The application expects CT slices encapsulated as DICOM files and allows the user to view several DICOM headers, anonymize the DICOM files in bulk by removing information in 2 tags, PatientName and PatientBirthDate, and
convert DICOM images to JPEG as well as allowing conversion the other way.

The key feature is a semi-automatic segmentation system whereby the user can annotate the boundaries of a region of prostrate in one slice and the application propagates this annotation into specified preceding as well as proceeding slices and constructs a 3D isosurface representation, along with
computing cross-sectional area and volume information. It is also possible to assign tags to annotations and save them.<br>

[> GitHub Repo : 3D Model From DICOM CTs](https://github.com/PamirGhimire/dicomGui){:target="_blank"}<br>

<hr><br>

<h2>Arduino Controlled four-digit display with buzzer</h2>
![ArduinoDisplay](/assets/projects_portfolio/ledDisplay.jpg){:class="img-responsive"}
This is a 4 digit display that uses four seven-segment displays and four shift registers. It also has a buzzer. It is controlled by an arduino uno. 
 
I am solely responsible for all pieces of the project, including but not limited to, hardware layout design and assembly, character design and tone design for the buzzer.
 
The link below will take you to a video that I had created to document this project. 
You'll need to pause the video to read the texts that appear in between clips. They are a little hard to make out.<br>

[> Video: Demo of the display](https://www.youtube.com/watch?v=sUaXQ-YNJ3k){:target="_blank"}<br>

<hr><br>

<h2>Magnetic Levitator</h2>
![Levitator](/assets/projects_portfolio/levitator.jpg){:class="img-responsive"}
This is a contraption that can levitate a light weight metallic object by dynamically balancing its weight with pulling force from an electromanget.

This is a project in active control using only analog components.

The controlled variable is the current through the electromagnet which is actively adjusted based on voltage inputs from two phototransistor-resistor potential dividers, one of which serves as a dynamic reference and the other as the object-tracker. <br>

[> Video: Demo of the levitator](https://www.youtube.com/watch?v=kBoDEasun_g){:target="_blank"}<br>

<hr><br>

<h2>Distance label predictor</h2>
![DistanceFromImagePredictor](/assets/projects_portfolio/distanceFromImage.gif){:class="img-responsive"}<br>
Problem: Given an image of a blob on a white chart paper, predict the distance label from which the image was taken.
 
Proposed solution: Take a set of images from different distance labels (distances corresponding to labels 1, 2, 3…). For each image, make a note of the distance label from which it was taken. Using these images and distance labels, develop an algorithm that learns the relation between (the information in) the images and their corresponding distance labels. Once the relation has been learned by the algorithm, use it to predict the distance labels of future images. <br>

[> Technical Report](https://drive.google.com/file/d/0ByxKumFMxsMAQmlHMjNJT3JuaTg/view){:target="_blank"}<br>

<hr><br>

<h2>Proximity Detector</h2>
![DistanceFromImagePredictor](/assets/projects_portfolio/proximityDetector.gif){:class="img-responsive"}<br>
A simple proximity made using spare parts from the levitator project. 

[> Circuit diagram and layout](https://drive.google.com/file/d/0ByxKumFMxsMAU3haYWNSVDR5RGM/view){:target="_blank"}<br>
