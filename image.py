from scipy.cluster.vq import kmeans2
import numpy as np
import argparse
from numpy import asarray
from PIL import Image
import pdb

ap = argparse.ArgumentParser()
ap.add_argument("-in","--input", type=str, help="path to input image")
ap.add_argument("-k","--k_val", type=int, help="path to input image")
args = vars(ap.parse_args())

img = Image.open(args['input'])
data = asarray(img)
shape = data.shape
data = data.astype('float').reshape(-1,3)

centroid,label = kmeans2(data,k = args['k_val'],minit = '++')

out = centroid[label].reshape(shape)

out_img = Image.fromarray(out.astype('uint8'), 'RGB')
out_img.save('Lenna_{}.png'.format(args['k_val']))