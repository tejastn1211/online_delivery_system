from flask import Flask, render_template, request, jsonify
import subprocess
import os

app = Flask(__name__)

# Helper to run C++ programs
def run_cpp(program, args=[]):
    try:
        result = subprocess.run(['./' + program] + args, capture_output=True, text=True)
        return {"status": "success", "output": result.stdout, "error": result.stderr}
    except Exception as e:
        return {"status": "error", "message": str(e)}

@app.route('/')
def home():
    return render_template('index.html')

@app.route('/customer', methods=['POST'])
def customer_action():
    action = request.form.get('action')
    if action == 'view':
        result = run_cpp('customer_portal')  # Adjust based on actual args
    return jsonify(result)

@app.route('/shopkeeper', methods=['POST'])
def shopkeeper_action():
    action = request.form.get('action')
    if action == 'add_item':
        item = request.form.get('item')
        result = run_cpp('shopkeeper_portal', ['add', item])
    return jsonify(result)

@app.route('/moderator', methods=['POST'])
def moderator_action():
    action = request.form.get('action')
    if action == 'list_users':
        result = run_cpp('moderator_portal')
    return jsonify(result)

if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0', port=5000)