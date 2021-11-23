const WebSocket = require('ws')
const wss = new WebSocket.Server({ port:8080 })
const performance = require('perf_hooks').performance

var t0
var t1

wss.on('connection', ws => {
  console.log('new client connected')

  var unsorted_list = []
  var sortMethodList = ['bubble', 'merge', 'insertion']

  packageToSend = {
    type: "list_unsorted",
    data: []
  }

  for(var i = 0; i < 1000; i++) {
    unsorted_list.push(Math.floor(Math.random() * 2000))
  }

  for(var i = 0; i < sortMethodList.length; i++) {
    packageToSend['data'] = unsorted_list
    packageToSend['method'] = sortMethodList[i]

    ws.send(JSON.stringify(packageToSend), () => {
      t0 = performance.now()
    })
  }

  // ws.send(JSON.stringify({
  //   type: "unsorted_list",
  //   data: [10, 23, 5, 20, 67, 13]
  // }))

  ws.on('message', msg => {
    t1 = performance.now()
    msg = JSON.parse(msg)
    msg['js_timing'] = (t1 - t0) * 1000

    console.log(`type of sorting method used: ${msg['method']}`)
    // console.log(`checking if returned list is properly sorted: ${msg['type']}`)
    console.log(`timing data as calculated from client: ${msg['timing']}`)
    console.log(`js timing: ${msg['js_timing']}`)
    console.log()

    // print the sorted list -- commented out to unclutter the console logs
    // console.log(`list returned from client (should be sorted now): ${msg['data']}`)

    // ws.send(data.toString().toUpperCase())
  })

  ws.on('close', () => {
    console.log('client has disconneted')
  })
})

console.log('server online...')