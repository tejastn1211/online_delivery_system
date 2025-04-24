function showTab(tabId) {
    document.querySelectorAll('.tab-content').forEach(tab => {
        tab.style.display = 'none';
    });
    document.getElementById(tabId).style.display = 'block';
}

function viewCustomer() {
    fetch('/customer', {
        method: 'POST',
        headers: { 'Content-Type': 'application/x-www-form-urlencoded' },
        body: 'action=view'
    })
    .then(response => response.json())
    .then(data => {
        document.getElementById('customer-output').textContent = 
            data.status === 'success' ? data.output : data.message;
    });
}

function addItem() {
    const item = document.getElementById('item-name').value;
    fetch('/shopkeeper', {
        method: 'POST',
        headers: { 'Content-Type': 'application/x-www-form-urlencoded' },
        body: `action=add_item&item=${item}`
    })
    .then(response => response.json())
    .then(data => {
        document.getElementById('shopkeeper-output').textContent = 
            data.status === 'success' ? data.output : data.message;
    });
}

function listUsers() {
    fetch('/moderator', {
        method: 'POST',
        headers: { 'Content-Type': 'application/x-www-form-urlencoded' },
        body: 'action=list_users'
    })
    .then(response => response.json())
    .then(data => {
        document.getElementById('moderator-output').textContent = 
            data.status === 'success' ? data.output : data.message;
    });
}