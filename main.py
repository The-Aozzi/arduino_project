import serial
from flask import Flask, jsonify
import flask_cors

app = Flask(__name__)
flask_cors.CORS(app)
ser = serial.Serial('COM12', 9600)


@app.route("/")
def main():
    
    out = ser.readline().decode()
    out = eval(out)
    print(out)
    return jsonify(out)