---
layout: default
title: Early project archive
permalink: /early-work/
---

<h1 class="page-heading">Early project archive</h1>
<p class="page-intro">Early professional work, research, coursework, and personal projects from before my career in automotive software. I keep them here as a record of the computer vision, robotics, imaging, and electronics work that shaped how I approach engineering today.</p>

<aside class="context-note">These projects represent my formative and early professional work rather than my current automotive role. My recent technical interests and experience are better represented by <a href="{{ '/writing/' | relative_url }}">my writing</a>.</aside>

<h3 class="project-heading" id="augmented-reality-in-image-guided-surgery">Augmented Reality in Image Guided Surgery</h3>
<p class="project-meta">2018–2019 · Early professional work</p>
![EnCoV_AR](/assets/projects_portfolio/encov.png){:class="img-responsive"}

This was my first professional role after completing my Master’s degree: Research Engineer at the EnCoV Lab from August 2018 to January 2019. I ported previously developed research code from MATLAB to C++ on Linux for non-rigid 3D–3D registration of a pre-operative organ model obtained from CT scans with an intraoperative model reconstructed from images captured during surgery. I implemented modules for voxelisation and tetrahedralization of 3D meshes, ICP-based registration, and numerical routines supporting model deformation. The work used libraries including Boost, Eigen, OpenCV, and Assimp, with development version-controlled using Git.<br>

[> Video : Real-time AR using the Sotware platform](https://www.youtube.com/watch?v=s39FkqLdQT4&feature=youtu.be){:target="_blank"}

<hr><br>

<h3 class="project-heading" id="cross-domain-visual-descriptors">Learning Local Descriptors for Comparing Renders with Real Images (MSc Thesis)</h3>
<p class="project-meta">2018 · Master’s thesis</p>
![DeepLearningTF](/assets/projects_portfolio/cnn_training_msc_thesis.JPG){:class="img-responsive"}

<b>Abstract</b> :  We present a method to train a deep network based feature descriptor to extract discriminative local descriptions from renders and corresponding real images with similar viewpoints and geometry. The work was done in context of inspection of mechanical assemblies for which 3D CAD models and approximate poses of the inspection camera were available. The descriptor was trained to best capture geometric features and stay invariant to image domain and rotation. Patch pairs for training the descriptor were extracted in a semi-supervised manner from a small dataset of less than 100 real images and corresponding renders with similar viewpoints which were manually registered to the real images. Due to the small size of training dataset, the descriptor network was initialized with weights from classification training on ImageNet. A two-step training was proposed for addressing the problem of domain shift. The first step,termed ’bootstrapping’, was a classification training to obtain good initial weights for second training step, the triplet-loss training, that provided weights for extracting discriminative embeddings that could be compared using L2-distance. The FPR95 score for the best descriptor was 13.8. ROC curves were plotted for comparing descriptors trained with different configurations. The descriptor was explored for comparing renders and real images through two approaches, first finding local correspondences between them through nearest neighbor matching of descriptors computed at FAST interest points, and second comparing crops of real images and renders by representing them as histograms based on Bag of Visual Words of the learned features. We observed that learning robust cross-domain rotation invariant descriptors is feasible, even with a small dataset, and such features may be of interest for various industrial applications like CAD based visual inspection, tracking, and finely registered augmented reality. To the best of our knowledge,this is the first work that reports learning local descriptors for comparing renders with real images

[> MSc Thesis : Matching Renders with Real Images using LearnedFeatures for Industrial Visual Inspection](/assets/msc_thesis_pamir.pdf){:target="_blank"}<br>

<hr><br>

<h3 class="project-heading" id="visual-servoing-with-ros">Visual Servoing of Turtlebot using ROS</h3>
<p class="project-meta">2017–2018 · Master’s coursework</p>
![Visual_Servoing](/assets/projects_portfolio/visualServoing.png){:class="img-responsive"}

Implemented image-points-based and pose-based visual servoing on Turtlebot 2 platform, using ROS and ViSP library. Gazebo was used for prototyping the implementations.
​
Pose based approach was implemented using a QR tag whose pose was automatically estimated in robot’s frame (using ViSP Autotracker).
The points-based approach required the user to manually select 4 centers in a known printed pattern of filled dots (blobs).
​
The visual servoing (fine positioning) task automatically followed after the completion of a map-based navigation task using a Multi-master setup in ROS.

[> Project Repo : GitHub](https://github.com/PamirGhimire/visualServoing_ROSProject){:target="_blank"}<br>
[> Video: Gazebo Demo](https://www.youtube.com/watch?v=qCdgKvE52iY){:target="_blank"}<br>
[> Video: Pose Based](https://www.youtube.com/watch?v=K4BQ3v-MSrs){:target="_blank"}<br>
[> Video: Image Points Based](https://www.youtube.com/watch?v=yDBamqhc0QQ){:target="_blank"}<br>
[> Video : Navigation + Visual Servoing](https://www.youtube.com/watch?v=hZTU4JiTiyA&feature=youtu.be){:target="_blank"}<br>

<hr><br>

<h3 class="project-heading">DICOM Manipulation Tool Using MATLAB</h3>
<p class="project-meta">2017 · Master’s coursework</p>
![CVToolbox](/assets/projects_portfolio/dicomGui.png){:class="img-responsive"}
A GUI based application for segmenting prostrate and its regions from CT (Computed Tomography) was developed in this lab work, using MATLAB. The application expects CT slices encapsulated as DICOM files and allows the user to view several DICOM headers, anonymize the DICOM files in bulk by removing information in 2 tags, PatientName and PatientBirthDate, and
convert DICOM images to JPEG as well as allowing conversion the other way.

The key feature is a semi-automatic segmentation system whereby the user can annotate the boundaries of a region of prostrate in one slice and the application propagates this annotation into specified preceding as well as proceeding slices and constructs a 3D isosurface representation, along with
computing cross-sectional area and volume information. It is also possible to assign tags to annotations and save them.<br>

[> GitHub Repo : 3D Model From DICOM CTs](https://github.com/PamirGhimire/dicomGui){:target="_blank"}<br>

<hr><br>

<h3 class="project-heading" id="hololens-for-radiation-safety">Hololens for Teaching Radiation Safety in Hybrid Operating Room</h3>
<p class="project-meta">2017 · Master’s internship</p>
![Hololens](/assets/projects_portfolio/hololens.png){:class="img-responsive"}
I developed a set of apps for Microsoft Hololens during a 3 months internship at research group CAMMA (Computational Analysis and Modelling  of Medical Activities) based in Strasbourg, France. The goal of the internship was to develop augmented/mixed reality applications for teaching radiation safety in a Hybrid operating room. Our work was accepted for a presentation at European Congress of Radiology, 2018. 
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

<h3 class="project-heading">Computer Vision Toolbox - (C++ &amp; OpenCV 3.2) and (MATLAB)</h3>
<p class="project-meta">2017 · Master’s coursework</p>
![CVToolbox](/assets/projects_portfolio/seeWithCpp.png){:class="img-responsive"}
The C++ and MATLAB toolboxes are (independent) collection of classes and functions on top of which GUIs were built, that allowed the user to perform image processing on single images, feature matching on (stereo) pair of images, and camera calibration using multiple images.
​
The C++ toolbox was built using OpenCV 3.2. I used a Model-View-Controller (MVC) pattern to design the application. All methods in the C++ toolbox were implemented as encapsulated algorithms to make them easy to use.<br>

[> GitHub Repo : C++ toolbox](https://github.com/PamirGhimire/seeWithCpp){:target="_blank"}<br>
[> GitHub Repo : MATLAB toolbox](https://github.com/PamirGhimire/seeWithMatlab_cppParallel){:target="_blank"}<br>
[> Video: Demo using C++ toolbox](https://www.youtube.com/watch?v=0kjDgor4Mn0){:target="_blank"}<br>

<hr><br>

<h3 class="project-heading">Distance Label Predictor</h3>
<p class="project-meta">2015 · Bachelor’s project</p>
![DistanceFromImagePredictor](/assets/projects_portfolio/distanceFromImage.gif){:class="img-responsive"}<br>
This was a project during my Bachelor of Electrical and Electronics Engineering at the National Institute of Technology Karnataka (NITK) in India. Its purpose was to predict the distance label (a discrete distance) from which an image was taken using only one image of a paper with an expected pattern.

My method: Take a set of images from different distance labels (distances corresponding to labels 1, 2, 3…). For each image, make a note of the distance label from which it was taken. Using these images and distance labels, fit a linear model that encodes the relation between the images and their corresponding distance labels. Once the relation has been 'learned' by the model, use it to predict the distance labels of images not seen during training. <br>

[> Technical Report](https://drive.google.com/file/d/0ByxKumFMxsMAQmlHMjNJT3JuaTg/view){:target="_blank"}<br>

<hr><br>

<h3 class="project-heading">Arduino-Controlled Four-Digit Display with Buzzer</h3>
<p class="project-meta">2013 · Bachelor’s personal project</p>
![ArduinoDisplay](/assets/projects_portfolio/ledDisplay.jpg){:class="img-responsive"}
This is a 4 digit display that uses four seven-segment displays and four shift registers. It also has a buzzer. It is controlled by an arduino uno. 
 
This was a solo summer-holiday project during which I designed the hardware layout, worked on the assembly of the board, character design in Arduino for the display and tone design for the buzzer.
 
The link below will take you to a video that I created to document this project. 
You'll need to pause the video to read the texts that appear in between clips.<br>

[> Video: Demo of the display](https://www.youtube.com/watch?v=sUaXQ-YNJ3k){:target="_blank"}<br>

<hr><br>

<h3 class="project-heading">Magnetic Levitator</h3>
<p class="project-meta">2011 · A-level personal project</p>
![Levitator](/assets/projects_portfolio/levitator.jpg){:class="img-responsive"}<br>

This is a contraption that can levitate a light weight metallic object by dynamically balancing its weight with pulling force from an electromanget.

This is a project in active control using only analog components.

The controlled variable is the current through the electromagnet which is actively adjusted based on voltage inputs from two phototransistor-resistor potential dividers, one of which serves as a dynamic reference and the other as the object-tracker. <br>

[> Video: Demo of the levitator](https://www.youtube.com/watch?v=kBoDEasun_g){:target="_blank"}<br>

<hr><br>

<h3 class="project-heading">Proximity Detector</h3>
<p class="project-meta">2011 · A-level personal project</p>
![Proximity detector demonstration](/assets/projects_portfolio/proximityDetector.gif){:class="img-responsive project-image-compact"}<br>
A simple proximity made using spare parts from the levitator project. The intensity of the LED is a function of the intensity of light reflected to a nearby LDR (photo-resistance) by a nearby object. 

<h4>Circuit diagram</h4>
![Hand-drawn circuit diagram for the proximity detector](/assets/projects_portfolio/proximityDetectorCircuit.png){:class="img-responsive project-image-compact"}

[> View the original circuit diagram and breadboard layout (PDF)](/assets/projects_portfolio/proximity_detector.pdf){:target="_blank"}<br>
