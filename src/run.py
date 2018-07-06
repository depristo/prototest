from __future__ import absolute_import
from __future__ import division
from __future__ import print_function

if __name__ == '__main__':
  print('-' * 40)
  print('hello, this is the first line of run.py')

  print('-' * 40)
  print('about to import api_implementation from protos to get version...')
  from google.protobuf.internal import api_implementation
  print('api_implementation.Type() says it uses the {} backend'.format(api_implementation.Type()))
  
  print('-' * 40)
  print('About to import our custom range_pb...')
  from src import range_pb2
  print('Successfully imported range_pb2')
  print('-' * 40)
  
  print('Creating our own range pb instance')
  range_ = range_pb2.Range(reference_name='chr1', start=10, end=20)
  print('range_ is:\n{}'.format(range_))
  print('-' * 40)
