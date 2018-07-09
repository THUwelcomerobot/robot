#!usr/bin/env python
#coding:utf-8

import cv2    
import face_recognition
import rospy
from std_msgs.msg import String 

class DetXRec(object):
	"""
	DESCRIPTION:
		class 'DetXRec' assembles both the face detection and the face recognition function,
		which will generate labeled images and lists of recognized individuals as the output.
	FUNCTION:
		- __init__()
		- compare_faces()
		- whoIsThis()	  
		- display()		  

	"""
	def __init__(self, templates):
		self.templates = templates
		self.images = []
		self.face_encodings = [] 
		self.names = []
		self.unknown_image_rgb = None
		self.name = None

		# loading templates (src_pictures) as the fudicial marks
		for template in self.templates:
			filename = '/home/robot/face_image/'+template + ".png" 
			try:			
				image = face_recognition.load_image_file(filename)  
			except IOError:
				print('template photo not found')
			else:
				self.images.append(image) 
		#print(len(self.images))

      	# encoding src_pictures
		for image in self.images:
			encoding = face_recognition.face_encodings(image)[0]  			
			self.face_encodings.append(encoding) 

	def compare_faces(self, dest):
		# global templates
		"""
 		DESCRIPTION:
 			compare_faces(self, dest) function executes the detection & recognition process,
 			and returns the labeled image as well as a list holding the names of the recogn
 			-ized individuals.

 		PARAMETER:
 			dest - string, indicating the path of the dest. picture
 		"""
		unknown_image = face_recognition.load_image_file(dest) 
		unknown_face_encodings = face_recognition.face_encodings(unknown_image) 
		face_locations = face_recognition.face_locations(unknown_image) 
		
		unknown_encoding = unknown_face_encodings[0]      
		face_location = face_locations[0]      
		top, right, bottom, left = face_location      
		cv2.rectangle(unknown_image, (left, top), (right, bottom), (0, 255, 0), 2)      
		results = face_recognition.compare_faces(self.face_encodings, unknown_encoding)
			# print(len(self.face_encodings),len(unknown_face_encodings))
			# print(len(self.images))
			      
		
		try:
			j = self.templates.index(True)
		# for j in range(len(results)):          
		#	if results[j]==True:
		except ValueError:
			self.name = 'unknown'
		else:
			self.name = self.templates[j]
		# self.names.append(name)
		cv2.putText(unknown_image, self.name, (left-10, top-10), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)        		 
		self.unknown_image_rgb = cv2.cvtColor(unknown_image, cv2.COLOR_BGR2RGB) 
		# return unknown_image_rgb

	def whoIsThis(self):
		return self.name

	def display(self):
		return self.unknown_image_rgb

# test
if __name__=='__main__':

	templates = ['2016011417','2016011000','2016011493'] 
	instance = DetXRec(templates) 
	instance.compare_faces('/home/robot/face_image/unknown.png')
	labeled_img = instance.display()
	cv2.imshow("Output", labeled_img) 
	cv2.waitKey(0)
	print(instance.whoIsThis())